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

import QtQuick 2.15
import QtQuick.Controls

Rectangle {
    id: rectangle
    width: 1280
    height: 720
    color: "#CECCAA"

    property var throttle_elem: throttleLever
    property real engine_power: 0.0

    Label {
        id: lblTrainProperties
        text: "Train weight: " + train.weight + "\nMax engine power: " + train.maxEnginePower
        color: "#333333"
    }

    Column {
        anchors.centerIn: parent

        Label {
            id: txtThrottlePos
            text: "Throttle: " + throttleLever.value
        }

        Slider {
            id: throttleLever
            from: 0
            to: 100
            stepSize: 1
            orientation: Qt.Vertical

            Connections {
                target: throttleLever
                function onValueChanged() { updateThrottle() }
            }
        }

        Label {
            id: txtEnginePower
            text: "Power: " + engine_power
        }
    }
}
