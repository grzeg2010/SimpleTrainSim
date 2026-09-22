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
#include <QChronoTimer>
#include <QDebug>
#include <QThread>

class Engine : public QObject
{
    Q_OBJECT

    double m_maxPower;
    Q_PROPERTY(int maxPower READ maxPower NOTIFY maxPowerChanged FINAL)
    double m_target_power;
    double m_current_power;
    Q_PROPERTY(double currentPower READ currentPower NOTIFY currentPowerChanged FINAL)
    double m_current_force;
    Q_PROPERTY(double currentForce READ currentForce NOTIFY currentForceChanged FINAL)
    double m_max_force;

    double m_throttle_pos;

public:
    explicit Engine(double max_power, QObject *parent = nullptr);

    int maxPower();
    void setMaxPower(int max_power);

    double currentPower();

    double currentForce();

signals:
    void maxPowerChanged();
    void currentPowerChanged();
    void currentForceChanged();

public slots:
    void calculate_force(double currentSpeedMps, double deltaTimeInSeconds);
    void read_throttle_change(int throttle_pos);
};

#endif // ENGINE_H
