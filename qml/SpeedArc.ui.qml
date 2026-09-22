import QtQuick 2.15
import QtQuick.Shapes

Shape {
    id: speedArc
    width: 200
    height: 200
    layer.enabled: true
    layer.samples: 4

    property real speed: 0
    property string strSpeed: "0.00";
    property real maxSpeed: 160

    ShapePath {
        id: bgPath
        fillColor: "transparent"
        strokeColor: "#CFC0AF"
        strokeWidth: 20
        capStyle: ShapePath.FlatCap
        PathAngleArc {
            centerX: speedArc.width / 2
            centerY: speedArc.height / 2
            radiusX: speedArc.width / 2 - bgPath.strokeWidth / 2
            radiusY: speedArc.height / 2 - bgPath.strokeWidth / 2
            startAngle: 135
            sweepAngle: 270
        }
    }

    ShapePath {
        id: fgPath
        fillColor: "transparent"
        // Complementary color for #F8F1E6
        strokeColor: "#577FA2"
        strokeWidth: 20
        capStyle: ShapePath.FlatCap
        PathAngleArc {
            centerX: speedArc.width / 2
            centerY: speedArc.height / 2
            radiusX: speedArc.width / 2 - fgPath.strokeWidth / 2
            radiusY: speedArc.width / 2 - fgPath.strokeWidth / 2
            startAngle: 135
            sweepAngle: 270 * (speed / maxSpeed)
        }
    }

    Text {
        anchors.centerIn: parent
        text: strSpeed
    }
}
