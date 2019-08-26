import QtQuick 2.0

Rectangle {
    id: imageRect
    property string image
    property bool active: false
    property double normalMultplier: 0.5
    property double activeMultiplier: 0.7

    property color activeColor: "red"
    property color inactiveColor: "black"

    anchors.top: parent.top
    anchors.right: parent.right
    width: parent.width * 0.05
    height: width
    color: (active) ? activeColor : inactiveColor
    Image {
        id: iconImage
        anchors.centerIn: parent
        width: parent.width * ((active)? activeMultiplier: normalMultplier)
        height: width
        source: imageRect.image
    }
// this component is not working on Raspberry - do sth wrong?
//    ColorOverlay {
//        id: colorOverlay
//        anchors.fill: iconImage
//        source: iconImage
//        color: (active)? activeColor : inactiveColor
//    }
}
