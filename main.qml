import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0

ApplicationWindow {
    visible: true
    width: 650
    height: 650
    title: qsTr("Battle City")

    Component.onCompleted: {
            setX(Screen.width / 2 - width / 2);
            setY(Screen.height / 2 - height / 2);
        }

    SwipeView {
        id: swipeView
        anchors.fill: parent

        Board {
            startButton.onClicked: {
                console.log("Start");
                startButton.visible = false;
            }
        }
    }

}
