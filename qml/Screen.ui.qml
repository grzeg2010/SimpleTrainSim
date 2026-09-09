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
import SimpleTrainSim

Rectangle {
    property Train train: null

    id: rectangle
    width: 1280
    height: 720
    color: "#CECCAA"

    Label {
        id: lblTrainProperties
        text: "Train weight: " + train.weight + "\nMax engine power: " + train.maxEnginePower
        color: "#333333"
    }

    Button {
        id: button
        text: qsTr("Horn")
        anchors.centerIn: parent

        Connections {
            target: button
            function onClicked() {
                train.useHorn();
            }
        }
    }
}
