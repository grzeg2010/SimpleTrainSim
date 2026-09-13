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

#include "combustionengine.h"

CombustionEngine::CombustionEngine(QObject *parent)
    : Engine{parent}
{}

double CombustionEngine::fuelLevel()
{
    return m_fuelLevel;
}

void CombustionEngine::setFuelLevel(double value)
{
    m_fuelLevel = value;
}

double CombustionEngine::maxForceFuelConsumption()
{
    return m_maxForceFuelConsumption;
}

void CombustionEngine::setMaxForceFuelConsumption(double value)
{
    m_maxForceFuelConsumption = value;
}

void CombustionEngine::add_fuel(double ammount)
{
    if(ammount < 0)
    {
        qWarning() << "Value of added fuel should be greater than 0.";
        return;
    }

    setFuelLevel(fuelLevel() + ammount);
}

void CombustionEngine::burn_fuel(double current_power)
{
    setFuelLevel((current_power / Engine::maxPower()) * maxForceFuelConsumption());
}
