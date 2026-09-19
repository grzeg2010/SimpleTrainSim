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
import local.grzeg2010.trainengine 0.1

Rectangle {
    id: rectangle
    width: 1280
    height: 720
    color: "#CECCAA"

    property var throttle_elem: throttleLever
    property alias powerIndicatorText: txtEnginePower.text
    property alias powerIndicatorBar: pbEnginePower.value
    focus: true

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
        }

        Label {
            id: txtEnginePower
            text: "0.00"
        }

        ProgressBar {
            id: pbEnginePower
            value: 0.0
        }
    }
}
