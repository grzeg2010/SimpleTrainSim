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
import SimpleTrainSim
import local.grzeg2010.train 0.1
import local.grzeg2010.trainengine 0.1

Item {
    property real currentPower: Train_engine.currentPower
    readonly property int maxPower: Train_engine.maxPower

    Keys.onPressed: event => {
        switch (event.key) {
            case Qt.Key_Z:
                form.throttle_elem.value += 2;
                break;
            case Qt.Key_A:
                form.throttle_elem.value -= 2;
                break;
            case Qt.Key_Q:
                form.throttle_elem.value = 0;
                break;
        }
    }

    Binding {
        id: throttle_binding
        target: Train;
        property: "throttlePos"
        value: form.throttle_elem.value
    }

    SimulationForm {
        id: form
        anchors.centerIn: parent
        powerIndicatorText: "Power: " + currentPower.toLocaleString(Qt.locale(), "f", 2);
        powerIndicatorBar: (currentPower / maxPower)
    }
}
