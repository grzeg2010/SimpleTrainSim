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

#include <algorithm>

#include "engine.h"

Engine::Engine(double max_power, QObject *parent)
    : QObject{parent}
{
    this->m_maxPower = max_power;
    this->m_current_power = 0.0;
    this->m_target_power = 0.0;
    this->m_current_force = 0.0;
    this->m_max_force = 300000.0;
    this->m_throttle_pos = 0.0;
}

void Engine::calculate_force(double currentSpeedMps, double deltaTimeInSeconds)
{
    // Prevent 0km/h lock in double max_power_at_current_speed and dividing by 0 in double tractiveForce
    double current_speed = std::max(0.8, std::abs(currentSpeedMps));

    double max_power_at_current_speed;

    // Cap speed at 39 m/s
    double start_fade_speed = 35.0;
    double fade_range = 4.0;
    if(current_speed < start_fade_speed)
        max_power_at_current_speed = m_max_force * current_speed;
    else
    {
        double drop_factor = std::max(0.0, 1.0 - ((current_speed - start_fade_speed) / fade_range));

        max_power_at_current_speed = m_max_force * current_speed * drop_factor;
    } // max speed 39 m/s
    double power_limiter = std::min(m_maxPower, max_power_at_current_speed);

    double target_power = power_limiter * m_throttle_pos;

    double powerChangeRate = 900000.0; // 900 kW/s
    if (m_current_power < target_power) {
        m_current_power += powerChangeRate * deltaTimeInSeconds;
        if (m_current_power > target_power) m_current_power = target_power;
    } else if (m_current_power > target_power) {
        m_current_power -= powerChangeRate * deltaTimeInSeconds * 6.0;
        if (m_current_power < target_power) m_current_power = target_power;
    }

    double tractiveForce = m_current_power / current_speed;

    m_current_force = std::min(m_max_force, tractiveForce);

    emit currentForceChanged();
    emit currentPowerChanged();
}

int Engine::maxPower() { return m_maxPower; }
void Engine::setMaxPower(int max_power) { m_maxPower = max_power; }

double Engine::currentPower() { return m_current_power; }

double Engine::currentForce() { return m_current_force; }

void Engine::read_throttle_change(int throttle_pos)
{
    m_throttle_pos = throttle_pos / 100.0;
}
