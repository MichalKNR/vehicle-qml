import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

Window {
    visible: true
    id: root
    width: 1366
    height: 768


    CircularGauge {
        x: parent.x + 0.1 * parent.width
        y: parent.y + 0.1 * parent.height
        value: AppData.value_speed
    }

    Image {
        anchors.centerIn: parent
        source: "../samochodzik.png"
    }

    Text {
        id: text
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
