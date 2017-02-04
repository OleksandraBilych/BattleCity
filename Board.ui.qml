import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    property alias startButton: startButton
    property alias mouseArea: mouseArea


        MouseArea {
                id: mouseArea
                width: 1024
                height: 960
                visible: true
                clip: false
                anchors.fill: parent
                Item {
                    id: item2
                    x: 295
                    y: 422
                    width: 50
                    height: 50
                    Player { x: 295; y: 0; width: 50; height: 50; anchors.horizontalCenterOffset: 0; anchors.horizontalCenter: parent.horizontalCenter; anchors.bottom: parent.bottom; anchors.bottomMargin: 0 }
                }
                Item {
                    id: item1
                    width: 100
                    height: 40
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    Button {
                        id: startButton
                        text: qsTr("Start")
                        //anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }

        }

}
