void Engine::calculate_force(double currentSpeedMps, ...)
{
    double current_speed = std::max(
        0.8, std::abs(currentSpeedMps)
    );
    // ...
    max_power_at_current_speed = m_max_force * current_speed;
    // ...
}