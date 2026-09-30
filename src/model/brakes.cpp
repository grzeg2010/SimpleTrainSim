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

#include "brakes.h"

Brakes::Brakes(QObject *parent)
    : QObject{parent}
{
    m_brake_pipe = 0.0;
    m_brake_pipe_max_charge = 5.0;
    m_cylinder = 4.0;
}

// void Brakes::chargeBrakePipe(double delta_time)
// {
//     if(m_brake_pipe < m_brake_pipe_max_charge)
//     {
//         m_brake_pipe += 0.08;
//     }

//     if(m_cylinder > 0.0)
//     {
//         m_cylinder -= 0.1;
//     }
// }

// void Brakes::chargeCylinder(int brake_lever_pos, double delta_time)
// {
//     int target_pipe_charge = m_brake_pipe_max_charge - (m_brake_pipe_max_charge * brake_lever_pos / 100.0);
//     if(m_brake_pipe > target_pipe_charge)
//     {
//         m_brake_pipe -= brake_lever_pos / 50.0 * delta_time;
//         m_cylinder += brake_lever_pos / 60.0 * delta_time;
//         if(m_brake_pipe < target_pipe_charge) m_brake_pipe = target_pipe_charge;
//     }
//     else if(m_brake_pipe < target_pipe_charge)
//     {
//         m_brake_pipe += brake_lever_pos / 80.0 * delta_time;
//         m_cylinder -= brake_lever_pos / 70.0 * delta_time;
//         if(m_cylinder < 0.0) m_cylinder = 0.0;
//     }
// }

double Brakes::brakePipe()
{
    return m_brake_pipe;
}

double Brakes::cylinder()
{
    return m_cylinder;
}

void Brakes::updateBrakes(int brake_lever_pos, double delta_time)
{
    double target_pipe_charge = m_brake_pipe_max_charge - (m_brake_pipe_max_charge * brake_lever_pos / 100.0);
    if(m_brake_pipe > target_pipe_charge)
    {
        m_brake_pipe -= brake_lever_pos / 50.0 * delta_time;
        m_cylinder += brake_lever_pos / 60.0 * delta_time;
        if(m_brake_pipe < target_pipe_charge) m_brake_pipe = target_pipe_charge;
    }
    else if(m_brake_pipe < target_pipe_charge)
    {
        m_brake_pipe += (100 - brake_lever_pos) / 80.0 * delta_time;
        m_cylinder -= (100 - brake_lever_pos) / 70.0 * delta_time;
        if(m_cylinder < 0.0) m_cylinder = 0.0;
    }

    emit brakePipeChanged();
    emit cylinderChanged();
}
