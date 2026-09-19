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

#include "engine.h"

Engine::Engine(int max_power, QObject *parent)
    : QObject{parent}
{
    this->m_maxPower = max_power;
    this->m_target_power = 0;
}

void Engine::calculate_power(double deltaTimeInSeconds)
{
    if(m_current_power == m_target_power) return;

    double responsivness = 2.5;

    if(m_current_power > m_target_power)
        responsivness = 8;

    double difference = m_target_power - m_current_power;

    m_current_power += difference * responsivness * deltaTimeInSeconds;

    if(std::abs(m_target_power - m_current_power) < 1) {
        m_current_power = m_target_power;
    }

    emit currentPowerChanged();
}

int Engine::maxPower() { return m_maxPower; }
void Engine::setMaxPower(int max_power) { m_maxPower = max_power; }

double Engine::currentPower() { return m_current_power; }

void Engine::read_throttle_change(int throttle_pos)
{
    m_target_power = throttle_pos / 100.0 * m_maxPower;
}
