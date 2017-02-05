import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0

import BattleCity 1.0

ApplicationWindow {
    visible: true
    width: 650
    height: 650
    title: qsTr("Battle City")
    color: "black"

    Component.onCompleted: {
            setX(Screen.width / 2 - width / 2);
            setY(Screen.height / 2 - height / 2);
        }

    Rectangle {
        id: board
        visible: false;
        focus: false

        Keys.onPressed: {
            if (event.key === Qt.Key_Left) {
                if ( sasha.direction == 270 ) {
                    if ( sasha.coordinate_x > 0) {
                        sasha.coordinate_x -= 10;
                    };
                } else {
                    sasha.direction = 270;
                }

                event.accepted = true;
            } else if (event.key === Qt.Key_Down) {
                if ( sasha.direction == 180 ) {
                    if ( sasha.coordinate_y < 600) {
                        sasha.coordinate_y += 10;
                    };
                } else {
                    sasha.direction = 180;
                }

                event.accepted = true;
             }
             else if (event.key === Qt.Key_Right) {
                if ( sasha.direction == 90 ) {
                    if ( sasha.coordinate_x < 600) {
                        sasha.coordinate_x += 10;
                    };
                } else {
                    sasha.direction = 90;
                }

                event.accepted = true;
             }
             else if (event.key === Qt.Key_Up) {
                if ( sasha.direction == 0 ) {
                    if ( sasha.coordinate_y > 0) {
                        sasha.coordinate_y -= 10;
                    }
                } else {
                    sasha.direction = 0;
                }

                event.accepted = true;
             }
        }

        Item {
            width: 650; height: 650


            Player {
                id: aPlayer
                x: sasha.coordinate_x;
                y: sasha.coordinate_y;
                width: 50;
                height: 50
                rotation: sasha.direction

                Image {
                    id: playerBackground
                    anchors.fill: parent
                    source: "qrc:/images/player.png"
                }
            }

            Enemy {
                id: aEnemy
                x: sirius.coordinate_x;
                y: sirius.coordinate_y;
                width: 50;
                height: 50
                rotation: sirius.direction

                Image {
                    id: enemyBackground
                    anchors.fill: parent
                    source: "qrc:/images/enemy.png"
                }
            }
        }
    }

    MouseArea {
        anchors.fill: parent

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            id: button1
            text: qsTr("Start")

            onClicked: {
                console.log("Start");
                visible = false;
                board.visible = true;
                board.focus = true;
            }
        }
    }
}
