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
along with this program.  If not, see <https://www.gnu.org/licenses/>.*/

#ifndef POWERINDICATOR_H
#define POWERINDICATOR_H

#include <QObject>

#include "engine.h"

class PowerIndicator : public QObject
{
    Q_OBJECT

    Engine *m_engine;

public:
    explicit PowerIndicator(Engine *engine, QObject *parent = nullptr);

    double m_currentPower;
    Q_PROPERTY(int currentPower READ currentPower WRITE setCurrentPower NOTIFY currentPowerChanged FINAL)

    double currentPower();

signals:
    void currentPowerChanged(double power);

private slots:
    void setCurrentPower(double power);
};

#endif // POWERINDICATOR_H
