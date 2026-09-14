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

#include "powerindicator.h"
#include "train.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    auto *active_train = new Train(20000, 6, 50, 15000, &app);
    //qmlRegisterSingletonType(QUrl("file:///absolute/path/SingletonType.qml"), "Qt.example.qobjectSingleton", 1, 0, "RegisteredSingleton");
    //context->setContextProperty("train", active_train);
    qmlRegisterSingletonInstance("local.grzeg2010.train", 0, 1, "Train", active_train);

    qInfo() << active_train->getEngineAddress();

    auto *power_indicator = new PowerIndicator(active_train->getEngineAddress(), active_train);
    qmlRegisterSingletonInstance("local.grzeg2010.powerindicator", 0, 1, "Power_indicator", power_indicator);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(QUrl(QStringLiteral("qrc:/qml/GUI.qml")));

    return QGuiApplication::exec();
}
