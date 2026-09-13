/* SimpleTrainSim - application immitating train HUD.
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
along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QQmlEngine>

class Engine : public QObject
{
    Q_OBJECT

    int m_maxPower;
    //Q_PROPERTY(int maxPower READ maxPower WRITE setMaxPower)

public:
    //explicit Engine(int max_power, QObject *parent = nullptr);
    explicit Engine(QObject *parent = nullptr);

    int maxPower();
    void setMaxPower(int max_power);

signals:
    void current_power(double value);

public slots:
    double calculate_power(int throttle_pos);
};

#endif // ENGINE_H
