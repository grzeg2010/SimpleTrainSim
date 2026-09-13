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

#ifndef COMBUSTIONENGINE_H
#define COMBUSTIONENGINE_H

#include <QDebug>

#include "engine.h"

class CombustionEngine : public Engine
{
    Q_OBJECT

    double m_fuelLevel;
    Q_PROPERTY(double fuelLevel READ fuelLevel WRITE setFuelLevel NOTIFY fuelLevelChanged FINAL)

    double m_maxForceFuelConsumption;
    Q_PROPERTY(double maxForceFuelConsumption READ maxForceFuelConsumption WRITE setMaxForceFuelConsumption NOTIFY maxForceFuelConsumptionChanged FINAL)

    double fuelLevel();
    void setFuelLevel(double value);

    double maxForceFuelConsumption();
    void setMaxForceFuelConsumption(double value);

public:
    explicit CombustionEngine(QObject *parent = nullptr);

    void add_fuel(double ammount);
    void burn_fuel(double current_power);

signals:
    void fuelLevelChanged();
    void maxForceFuelConsumptionChanged();
};

#endif // COMBUSTIONENGINE_H
