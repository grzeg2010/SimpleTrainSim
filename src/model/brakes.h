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

#ifndef BRAKES_H
#define BRAKES_H

#include <QObject>

class Brakes : public QObject
{
    Q_OBJECT
    double m_brake_pipe;
    double m_brake_pipe_max_charge;
    double m_cylinder;

    Q_PROPERTY(double brakePipe READ brakePipe NOTIFY brakePipeChanged FINAL)
    Q_PROPERTY(double cylinder READ cylinder NOTIFY cylinderChanged FINAL)

    // Reservoirs are infinite
    // void chargeBrakePipe(double delta_time); // max 5kg/cm^2 used (which is 0.5 MPa)
    // void chargeCylinder(int brake_lever_pos, double delta_time);
public:
    explicit Brakes(QObject *parent = nullptr);

    double brakePipe();
    double cylinder();

signals:
    void brakePipeChanged();
    void cylinderChanged();

public slots:
    void updateBrakes(int brake_lever_pos, double delta_time);
};

#endif // BRAKES_H
