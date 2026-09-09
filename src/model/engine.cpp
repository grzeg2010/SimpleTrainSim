#include "engine.h"

Engine::Engine(QObject *parent)
    : QObject{parent}
{}

int Engine::maxPower() { return m_maxPower; }
void Engine::setMaxPower(int max_power) { m_maxPower = max_power; }

double Engine::calculate_power(int throttle_pos)
{
    double power = throttle_pos * m_maxPower;
    emit current_power(power);
    return power;
}
