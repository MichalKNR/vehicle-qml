import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4
import QtCharts 2.2
import "helper"



Window {
    visible: true
    id: root
    visibility: "FullScreen"
    color: Qt.rgba(0, 0, 0, 1);

    MyCircualGauge {
        id: circularGauge
        size: parent.width * 0.3
        y: parent.y + 0.09 * parent.height
        x: parent.x + 0.05 * parent.width
    }

    Image {
        id: logoEmaxPower
        width: parent.width * 0.4
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit
        source: "qrc:/images/emakspower_white.png"
    }


    Image {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height * 0.01
        height: parent.height * 0.85
        source: "../images/samochodzik1.png"
        fillMode: Image.PreserveAspectFit
    }

    // steer
    ReferenceLine {
        value_name: "steer"
        xPosition: parent.width / 2
        yPosition: parent.height * 0.3
    }

    // engine
    ReferenceLine {
        value_name: "engine"
        xPosition: parent.width / 2
        yPosition: parent.height * 0.85
    }



    Battery {
        x: parent.width / 2 - width / 2
        y: parent.height * 0.65 - height / 2
        batteryColor: "grey"
        width: parent.width * 0.04
        height: parent.height * 0.1
    }

    // Battery
    ReferenceLine {
        value_name: "battery"
        xPosition: parent.width / 2
        yPosition: parent.height * 0.65
    }

    ChartView {
        id: chartView
        x: parent.width * 0.03
        y: parent.height * 0.6
        width: parent.width * 0.35
        height: parent.height * 0.4
        antialiasing: true
        backgroundColor: "transparent"

        LineSeries {
            name: "Pobór mocy"
            XYPoint { x: 0; y: 0 }
            XYPoint { x: 1.1; y: 2.1 }
            XYPoint { x: 1.9; y: 3.3 }
            XYPoint { x: 2.1; y: 2.1 }
            XYPoint { x: 2.9; y: 4.9 }
            XYPoint { x: 3.4; y: 3.0 }
            XYPoint { x: 4.1; y: 3.3 }
        }
    }

    //icons

    Icon {
        id: iconAlarm
        anchors.top: parent.top
        anchors.right: parent.right
        width: parent.width * 0.05
        height: width

        image: "../../images/notificationWhite.png"
        active: AppData.valueAlarmOn
        normalMultplier: 0.3
    }

    Icon {
        id: iconUnderLights
        anchors.top: parent.top
        anchors.right: iconAlarm.left
        width: parent.width * 0.05
        height: width
        image: "../../images/car-lightsWhite.png"
        active: AppData.valueUnderLightsOn
    }

    Icon {
        id: iconCheckEngine
        anchors.top: parent.top
        anchors.right: iconUnderLights.left
        width: parent.width * 0.05
        height: width
        image: "../../images/checkEngineWhite.png"
        active: AppData.valueCheckEngineOn
    }

    Icon {
        id: iconConnection
        anchors.top: parent.top
        anchors.right: iconCheckEngine.left
        width: parent.width * 0.05
        height: width

        image: "../../images/wifi-connection-signal-symbolWhite.png"
        active: !AppData.server_connected
        normalMultplier: 0.4
        activeMultiplier: 0.5
    }
}
