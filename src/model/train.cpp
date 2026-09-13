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

#include "train.h"

Train::Train(QObject *parent)
    : QObject{parent}
{
    this->m_engine = new ElectricEngine(this);

    QObject::connect(this, &Train::throttlePosChanged, m_engine, &Engine::calculate_power);
    QObject::connect(m_engine, &Engine::current_power, this, &Train::setCurrentPower);
}

void Train::setThrottlePos(int position)
{
    m_throttlePos = position;
    emit throttlePosChanged(m_throttlePos);
}

void Train::setBrakeLeverPos(int position)
{
    m_brakeLeverPos = position;
}

int Train::weight() { return m_weight; }
void Train::setWeight(int weight) { m_weight = weight; }
int Train::axlesCount() { return m_axlesCount; }
int Train::throttlePos() { return m_throttlePos; }
int Train::brakeLeverPos() { return m_brakeLeverPos; }
int Train::aerodynamicEfficiency() { return m_aerodynamicEfficiency; }

int Train::maxEnginePower() { return m_engine->maxPower(); }
void Train::setMaxEnginePower(int max_power) { m_engine->setMaxPower(max_power); }
double Train::currentPower() { return m_currentPower; }
void Train::setCurrentPower(double power)
{
    m_currentPower = power;
    emit currentPowerChanged(power);
}