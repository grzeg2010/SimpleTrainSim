

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls

Item {
    id: item1
    width: 300
    height: 300

    property double bpPercentage: 0.0
    property double cylinderPercentage: 0.0

    Rectangle {
        id: circle
        width: parent.width - 5
        height: width
        color: "#333333"
        radius: width / 2
        border.width: width * 0.03
        anchors.centerIn: parent

        Item {
            id: gaugeLines
            anchors.fill: parent

            Rectangle {
                id: line00
                width: 5
                height: (parent.height / 2) - 15
                color: "#eeeeee"
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 0
                rotation: -135
                transformOrigin: Item.Bottom
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                id: line01
                width: line00.width
                height: line00.height
                color: line00.color
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 0
                transformOrigin: Item.Bottom
                rotation: -108
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                id: line02
                y: 0
                width: line00.width
                height: line00.height
                color: line00.color
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 0
                anchors.horizontalCenterOffset: 0
                transformOrigin: Item.Bottom
                rotation: -81
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                id: line03
                width: line00.width
                height: line00.height
                color: line00.color
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 0
                transformOrigin: Item.Bottom
                rotation: -54
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                id: line04
                width: line00.width
                height: line00.height
                color: line00.color
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 0
                transformOrigin: Item.Bottom
                rotation: -27
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                id: line05
                width: line00.width
                height: line00.height
                color: line00.color
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 0
                anchors.horizontalCenter: parent.horizontalCenter
                transformOrigin: Item.Bottom
            }

            Rectangle {
                id: line06
                width: line00.width
                height: line00.height
                color: line00.color
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 0
                transformOrigin: Item.Bottom
                rotation: 27
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                id: line07
                width: line00.width
                height: line00.height
                color: line00.color
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 0
                rotation: 54
                transformOrigin: Item.Bottom
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                id: line08
                width: line00.width
                height: line00.height
                color: line00.color
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 0
                transformOrigin: Item.Bottom
                rotation: 81
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                id: line09
                width: line00.width
                height: line00.height
                color: line00.color
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 0
                transformOrigin: Item.Bottom
                rotation: 108
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                id: line10
                width: line00.width
                height: line00.height
                color: line00.color
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 0
                transformOrigin: Item.Bottom
                rotation: 135
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Rectangle {
            id: circleInner
            x: 48
            y: 48
            width: 200
            height: width
            color: circle.color
            radius: width / 2
            border.width: 0
            anchors.centerIn: parent
        }

        Item {
            id: unitsTextContainer
            anchors.fill: parent
            z: 0

            Label {
                id: label00
                x: 72
                y: 201
                color: "#eeeeee"
                text: qsTr("0.0")
            }

            Label {
                id: label02
                x: 55
                y: 122
                color: "#eeeeee"
                text: qsTr("0.2")
            }

            Label {
                id: label04
                x: 101
                y: 63
                color: "#eeeeee"
                text: qsTr("0.4")
            }

            Label {
                id: label06
                x: 177
                y: 63
                color: "#eeeeee"
                text: qsTr("0.6")
            }

            Label {
                id: label08
                x: 221
                y: 122
                color: "#eeeeee"
                text: qsTr("0.8")
            }

            Label {
                id: label10
                x: 193
                y: 201
                color: "#eeeeee"
                text: qsTr("1.0")
            }
        }

        Item {
            id: centerTextContainer
            anchors.fill: parent

            Label {
                id: unit
                y: item1.width * 0.566
                color: "#eeeeee"
                text: qsTr("MPa")
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: item1.width * 0.046
                font.bold: true
                font.family: "Verdana"
            }

            Label {
                id: yellowLabel
                y: item1.width * 0.65
                color: "#ffee00"
                text: qsTr("BP")
                font.pointSize: item1.width * 0.046
                font.family: "Verdana"
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Label {
                id: redLabel
                y: item1.width * 0.73
                color: "#ff0000"
                text: qsTr("Cylinder")
                font.pointSize: item1.width * 0.046
                font.family: "Verdana"
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Rectangle {
            id: needleYellow
            width: item1.width * 0.0166
            height: (parent.height / 2) - 10
            color: "#ffee00"
            anchors.bottom: parent.verticalCenter
            transformOrigin: Item.Bottom
            z: 1
            rotation: -135 + (270 * bpPercentage)
            anchors.horizontalCenter: parent.horizontalCenter

            Rectangle {
                id: rectangle
                width: parent.width * 2
                height: width
                color: parent.color
                anchors.top: parent.bottom
                rotation: 45
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Rectangle {
            id: needleRed
            width: item1.width * 0.0166
            height: (parent.height / 2) - 10
            color: "#ff0000"
            anchors.bottom: parent.verticalCenter
            anchors.bottomMargin: 0
            z: 1
            rotation: -135 + (270 * cylinderPercentage)
            transformOrigin: Item.Bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            id: dotInnerCenter
            width: item1.width * 0.033
            height: width
            color: "#777777"
            radius: width / 2
            border.width: 0
            z: 2
            anchors.centerIn: parent
        }
    }
}
