/*
SimpleTrainSim - application immitating train HUD.
Copyright (C) 2026 Grzegorz Śnieżko

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>
#include <QElapsedTimer>

#include "train.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    auto *step_timer = new QChronoTimer(&app);
    auto *delta_timer = new QElapsedTimer();
    delta_timer->start();

    auto *active_train = new Train(20000, 6, 50, 15000, &app);
    qmlRegisterSingletonInstance("local.grzeg2010.train", 0, 1, "Train", active_train);

    qmlRegisterSingletonInstance("local.grzeg2010.trainengine", 0, 1, "Train_engine", active_train->getEngineAddress());

    QObject::connect(step_timer, &QChronoTimer::timeout, active_train->getEngineAddress(), [=]() {
        double delta_time = delta_timer->restart() / 1000.0;
        active_train->getEngineAddress()->calculate_power(delta_time);
    });
    step_timer->setInterval(std::chrono::milliseconds(16));
    step_timer->start();

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(QUrl(QStringLiteral("qrc:/qml/GUI.qml")));

    return QGuiApplication::exec();
}
