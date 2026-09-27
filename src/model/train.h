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

#ifndef TRAIN_H
#define TRAIN_H

#include <QObject>
#include <QDebug>
#include <QThread>

#include "brakes.h"
#include "engine.h"
#include "electricengine.h"

class Train : public QObject
{
    Q_OBJECT

    int m_weight;
    Q_PROPERTY(int weight READ weight WRITE setWeight FINAL)

    int m_axlesCount;
    Q_PROPERTY(int axlesCount READ axlesCount FINAL)

    int m_throttlePos;
    Q_PROPERTY(int throttlePos READ throttlePos WRITE setThrottlePos NOTIFY throttlePosChanged FINAL)

    int m_brakeLeverPos;
    Q_PROPERTY(int brakeLeverPos READ brakeLeverPos WRITE setBrakeLeverPos NOTIFY brakeLeverPosChanged FINAL)

    int m_aerodynamicEfficiency; // percent 0-100
    Q_PROPERTY(int aerodynamicEfficiency READ aerodynamicEfficiency FINAL)

    double m_speed;
    Q_PROPERTY(double speed READ speed NOTIFY speedChanged FINAL)

    QThread m_engineThread;
    Engine *m_engine;
    Q_PROPERTY(int maxEnginePower READ maxEnginePower WRITE setMaxEnginePower FINAL)

    Brakes *m_brakes;

public:
    explicit Train
    (
        int weight, int axles_count, int aerodynamic_efficiency,
        double max_engine_power,
        QObject *parent = nullptr
    );

    ~Train();

    Q_INVOKABLE void setThrottlePos(int position);
    Q_INVOKABLE void setBrakeLeverPos(int position);

    int weight();
    void setWeight(int weight);

    int axlesCount();
    int throttlePos();
    int brakeLeverPos();
    int aerodynamicEfficiency();
    double speed();

    Engine* getEngineAddress();
    int maxEnginePower();
    void setMaxEnginePower(int max_power);

    Brakes* getBrakesAddress();

signals:
    void throttlePosChanged(int throttle_pos);
    void brakeLeverPosChanged();
    void speedChanged();

public slots:
    void calculate_speed(double deltaTimeInSeconds);
};

#endif // TRAIN_H
