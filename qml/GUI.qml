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

import QtQuick 2.15
import QtQuick.Controls.Basic
import SimpleTrainSim

ApplicationWindow {
    id: window
    width: 1280
    height: 720

    visible: true
    title: qsTr("SimpleTrainSim")

    Train {
        id: train
        weight: 20000
        maxEnginePower: 1500
    }

    Simulation {
        id: simulationScreen
        train: train

        anchors.centerIn: parent
    }
}
