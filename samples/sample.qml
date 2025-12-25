/*
Header comment 
*/

import QtQuick
import MyModule

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Model {
        id: model
    }

    // comment
    Rectangle {
        width: 100
        height: 100
        color: "#fff000"
        MouseArea {
            anchors.fill: parent
            onClicked: model.call1()
        }
    }
}
