import QtQuick 2.0

Rectangle {
    id: batteryRoot
    width: 40
    height: 60
    property string batteryColor: "white"
    property string  batteryBackgroundColor: "lightgrey"
    Rectangle {
        id: batteryNeck
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.5
        height: parent.height * 0.1
        color: batteryColor
    }
    Rectangle {
        width: parent.width
        height: parent.height - batteryNeck.height
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        color: batteryBackgroundColor

        property int borderWidth: parent.width * 0.1
        Rectangle {
            z: 1
            id: batteryBody
            anchors.fill: parent
            border.color: batteryColor
            border.width: parent.width * 0.1
            color: "transparent"
        }
        property int percent: 100

        Rectangle {
            z: 0
            id: batteryContent
            width: parent.width
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            height: (AppData.valueBatteryPercent < 0 || AppData.valueBatteryPercent > 100)? 0 :
                parent.width * 0.1 +  (batteryBody.height - 2 * parent.width * 0.1) / 100 * AppData.valueBatteryPercent
            color: "green"
        }
    }



    color: "transparent"

}
