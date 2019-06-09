import QtQuick 2.0

Item {
    property string value_name: "unknown"
    property int xPosition: 0
    property int yPosition: 0

    Rectangle {
        id: lineSteer
        x: xPosition
        y: yPosition
        width: root.width * 0.25
        height: 5
        radius: height
        color: "white"
    }

    Text {
        id: steerTemp
        text: (value_name == "steer")? AppData.valueSteerTemperature + "°C" :
              (value_name == "engine")? AppData.valueEngineTemperature + "°C" :
              (value_name == "battery")? AppData.valueBatteryTemperature + "°C" : ""
        anchors.left: lineSteer.right
        anchors.bottom: lineSteer.top
        font.pixelSize: root.height * 0.05
        color: "white"
    }

    Text {
        id: steerAcc
        text: (value_name == "steer")? AppData.valueSteerAccurancy + "A" :
              (value_name == "engine")? AppData.valueEngineAccurancy + "A" :
              (value_name == "battery")? AppData.valueBatteryAccurancy + "A" : ""
        anchors.left: lineSteer.right
        anchors.top: lineSteer.bottom
        font.pixelSize: root.height * 0.05
        color: "white"
    }
}
