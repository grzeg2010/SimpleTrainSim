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

Train::Train
(
    int weight, int axles_count, int aerodynamic_efficiency,
    double max_engine_power,
    QObject *parent
)
    : QObject{parent}
{
    this->m_weight = weight;
    this->m_axlesCount = axles_count;
    this->m_aerodynamicEfficiency = aerodynamic_efficiency;
    this->m_speed = 0.0;
    this->m_throttlePos = 0;

    this->m_engine = new ElectricEngine(max_engine_power, this);
    connect(this, &Train::throttlePosChanged, m_engine, &Engine::read_throttle_change);

    this-> m_brakes = new Brakes(this);
}

Train::~Train()
{
    m_engineThread.quit();
    m_engineThread.wait();
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
double Train::speed() { return m_speed; }

Engine* Train::getEngineAddress() { return m_engine; }
int Train::maxEnginePower() { return m_engine->maxPower(); }
void Train::setMaxEnginePower(int max_power) { m_engine->setMaxPower(max_power); }

Brakes* Train::getBrakesAddress() { return m_brakes; }

void Train::calculate_speed(double deltaTimeInSeconds)
{
    m_engine->calculate_force(m_speed, deltaTimeInSeconds);
    m_brakes->updateBrakes(m_brakeLeverPos, deltaTimeInSeconds);

    double speed_kmh = std::abs(m_speed) * 3.6;

    double weight_in_tonnes = m_weight / 1000.0;
    double weight_per_axle = weight_in_tonnes / m_axlesCount;

    double davis_A = 6.374 + (129 / weight_per_axle);
    double davis_B = 0.1371 * speed_kmh;
    double frontal_area = 12.3;
    double davis_C = (0.009243 * frontal_area * speed_kmh * speed_kmh) / weight_in_tonnes;
    double braking_force = m_brakes->cylinder() * 1000;

    double total_resistance_force = (davis_A + davis_B + davis_C + braking_force) * weight_in_tonnes;

    double tractive_force = m_engine->currentForce();

    double net_force = 0.0;

    if (m_speed >= 0.0)
    {
        net_force = tractive_force - total_resistance_force;
    }

    double acceleration = net_force / m_weight;

    // TODO
    // Train must not have negative speed
    // Going forward will increase travelled distance by speed
    // Going backward will decrease travelled distance by speed
    // State of enum TRAIN_REVERSER must decide if distance will be increased or decreased
    if (m_speed + acceleration < 0.0)
    {
        m_speed = 0.0;
    }
    else
    {
        m_speed += acceleration * deltaTimeInSeconds;
    }

    emit speedChanged();
    // qInfo() << "Engine force:" << tractive_force;
}

// USEFUL LINKS
// https://en.wikipedia.org/wiki/Traction_(mechanics)
// https://en.wikipedia.org/wiki/Tractive_effort
// https://en.wikipedia.org/wiki/Adhesion_railway
// https://en.wikipedia.org/wiki/Acceleration
// https://en.wikipedia.org/wiki/Mass#Inertial_vs._gravitational_mass
// https://www.combustion-engines.eu/pdf-184051-110080?filename=Determination%20of%20the.pdf
// https://www.coalstonewcastle.com.au/physics/resistance/