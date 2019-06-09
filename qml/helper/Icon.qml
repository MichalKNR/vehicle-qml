import QtQuick 2.0
import QtGraphicalEffects 1.12

Rectangle {
    id: imageRect
    property string image
    property bool active: false
    property double normalMultplier: 0.5
    property double activeMultiplier: 0.7

    property string activeColor: "red"
    property string inactiveColor: "white"

    anchors.top: parent.top
    anchors.right: parent.right
    width: parent.width * 0.05
    height: width
    color: "black"
    Image {
        id: iconImage
        anchors.centerIn: parent
        width: parent.width * ((active)? activeMultiplier: normalMultplier)
        height: width
        source: image
    }
    ColorOverlay {
        id: colorOverlay
        anchors.fill: iconImage
        source: iconImage
        color: (active)? activeColor : inactiveColor
    }

    onActiveChanged: {
        if (active) {
            colorOverlay.color = activeColor
        } else {
            colorOverlay.color = inactiveColor
        }
    }

    onImageChanged: {
        iconImage.source = imageRect.image
    }
}
