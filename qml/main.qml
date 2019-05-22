import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4
import QtCharts 2.2


Window {
    visible: true
    id: root
    width: 1366
    height: 768


    CircularGauge {
        x: parent.x + 0.1 * parent.width
        y: parent.y + 0.1 * parent.height
        value: AppData.value_speed
        maximumValue: 200
    }

    Image {
        anchors.centerIn: parent
        source: "../samochodzik.png"
    }

    Rectangle {
        id: lineSteer
        x: parent.width / 2
        y: parent.height * 0.3
        width: parent.width * 0.3
        height: 5
        radius: height
        color: "black"
    }

    Text {
        id: steerTemp
        text: AppData.valueSteerTemperature + "°C"
        anchors.right: lineSteer.right
        anchors.bottom: lineSteer.top
    }

    Text {
        id: steerAcc
        text: AppData.valueSteerAccurancy + "A"
        anchors.right: lineSteer.right
        anchors.top: lineSteer.bottom
    }

    Rectangle {
        id: lineEngine
        x: parent.width / 2
        y: parent.height * 0.75
        width: parent.width * 0.3
        height: 5
        radius: height
        color: "black"
    }

    Text {
        id: engineTemp
        text: AppData.valueEngineTemperature + "°C"
        anchors.right: lineEngine.right
        anchors.bottom: lineEngine.top
    }


    Text {
        id: engineAcc
        text: AppData.valueEngineAccurancy + "A"
        anchors.right: lineEngine.right
        anchors.top: lineEngine.bottom
    }

    ChartView {
        x: parent.width * 0.03
        y: parent.height * 0.6
        width: parent.width * 0.35
        height: parent.height * 0.4
        antialiasing: true

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

    Text {
        anchors.centerIn: parent
        visible: !AppData.server_connected
        text: "Brak połączenia z serwerem"
        color: "red"
        font.pixelSize: 50
    }
}
