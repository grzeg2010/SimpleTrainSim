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
import QtQuick.Controls.Basic
import SimpleTrainSim

ApplicationWindow {
    id: window
    width: mainScreen.width
    height: mainScreen.height

    visible: true
    title: qsTr("SimpleTrainSim")

    Train {
        id: train
        onHorn: useTime => {
            lblUseTime.text = useTime
            popup.open();
        }
    }

    Popup {
        id: popup
        anchors.centerIn: parent
        width: 300
        height: 100
        modal: true
        visible: false
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        Column {
            spacing: 5

            Label {
                text: "Horn!"
            }

            Label {
                id: lblUseTime
                text: ""
            }
        }
    }

    Screen {
        id: mainScreen
        train: train

        anchors.centerIn: parent
    }
}
