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
import local.grzeg2010.trainengine 0.1

Rectangle {
    id: rectangle
    width: 1280
    height: 720
    color: "#F8F1E6"
    focus: true

    property alias throttle_elem: throttleLever
    property alias powerIndicatorText: txtEnginePower.text
    property alias powerIndicatorBar: pbEnginePower.value
    property alias speed: arcSpeed.speed
    property alias strSpeed: arcSpeed.strSpeed
    property alias brakesLever_item: brakesLever
    property alias brakePipeText: txtBrakePipe.text
    property alias brakeCylinderText: txtBrakeCylinder.text

    Row {
        anchors.centerIn: parent

        Column {
            Label {
                id: txtThrottlePos
                text: "Throttle: " + throttleLever.value
            }

            Row {
                spacing: 20
                Slider {
                    id: throttleLever
                    from: 0
                    to: 100
                    stepSize: 1
                    orientation: Qt.Vertical
                }

                ProgressBar {
                    id: pbEnginePower
                    anchors.top: throttleLever.bottom
                    anchors.bottomMargin: 0
                    height: 20
                    width: throttleLever.height
                    transformOrigin: Item.TopLeft
                    rotation: 270
                    value: 0.0

                    background: Rectangle {
                        width: parent.width
                        color: "#CFC0AF"
                        Repeater {
                            model: parent.width / 20
                            Image {
                                x: index * 20
                                y: 0
                                source: `data:image/svg+xml;utf8,
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 20 20">
                                        <path fill="none" stroke="#3C332F" d="M 0 0 L 0 20" />
                                        </svg>`
                            }
                        }
                    }

                    contentItem: Rectangle {
                        width: parent.visualPosition * parent.width
                        color: "#917444"
                    }
                }
            }

            Label {
                id: txtEnginePower
                text: "0.00"
            }
        }

        SpeedArc {
            id: arcSpeed
            maxSpeed: 160
        }

        Column {
            Label {
                id: txtBrakePos
                text: "Brakes lever: " + brakesLever.value
            }

            Slider {
                id: brakesLever
                from: 0
                to: 100
                stepSize: 1
                orientation: Qt.Vertical
            }

            Label {
                id: txtBrakePipe
            }

            Label {
                id: txtBrakeCylinder
            }
        }
    }
}
