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

    function proceedMovement() {
        var step = 10;
        var limixX = width - aPlayer.width;
        var limitY = height - aPlayer.height;

        if (aPlayer.moveUp && sasha.coordinate_y - step > 0) {
            if (sasha.direction != 0) {
                sasha.direction = 0;
            } else {
                sasha.coordinate_y -= step;
            }
        } else if (sasha.coordinate_y < 0) {
            sasha.coordinate_y = 0;
        }

        if (aPlayer.moveDown && sasha.coordinate_y + step < limitY) {
            if (sasha.direction != 180) {
                sasha.direction = 180;
            } else {
                sasha.coordinate_y += step;
            }
        } else if (sasha.coordinate_y > limitY) {
            sasha.coordinate_y = limitY;
        }

        if (aPlayer.moveLeft && sasha.coordinate_x - step > 0) {
            if (sasha.direction != 270) {
                sasha.direction = 270;
            } else {
                sasha.coordinate_x -= step;
            }
        } else if (sasha.coordinate_x < 0) {
            sasha.coordinate_x = 0;
        }

        if (aPlayer.moveRight && sasha.coordinate_x + step < limixX) {
            if (sasha.direction != 90) {
                sasha.direction = 90;
            } else {
                sasha.coordinate_x += step;
            }
        } else if (sasha.coordinate_x > limixX) {
            sasha.coordinate_x = limixX;
        }
    }

    Item {
        Rectangle {
            id: board
            width: 650
            height: 650
            visible: false
            focus: false
            color: "black"

            Timer  {
                id: playerMoveTimer
                interval: 100;
                running: true;
                repeat: true;
                onTriggered: proceedMovement();
            }

            Keys.onPressed: {
                if (event.key == Qt.Key_Left) {
                    aPlayer.moveLeft = true;
                    aPlayer.moveRight = false;
                    aPlayer.moveUp = false;
                    aPlayer.moveDown = false;
                } else if (event.key == Qt.Key_Right) {
                    aPlayer.moveLeft = false;
                    aPlayer.moveRight = true;
                    aPlayer.moveUp = false;
                    aPlayer.moveDown = false;
                } else if (event.key == Qt.Key_Up) {
                    aPlayer.moveLeft = false;
                    aPlayer.moveRight = false;
                    aPlayer.moveUp = true;
                    aPlayer.moveDown = false;
                } else if (event.key == Qt.Key_Down) {
                    aPlayer.moveLeft = false;
                    aPlayer.moveRight = false;
                    aPlayer.moveUp = false;
                    aPlayer.moveDown = true;
                }

                //proceedMovement();

                event.accepted = true;
            }

            Keys.onReleased: {
                if (event.key == Qt.Key_Left) {
                    aPlayer.moveLeft = false;
                } else if (event.key == Qt.Key_Right) {
                    aPlayer.moveRight = false;
                } else if (event.key == Qt.Key_Up) {
                    aPlayer.moveUp = false;
                } else if (event.key == Qt.Key_Down) {
                    aPlayer.moveDown = false;
                }

                event.accepted = true;
            }

            Player {
                id: aPlayer
                x: sasha.coordinate_x;
                y: sasha.coordinate_y;
                width: 50;
                height: 50
                rotation: sasha.direction

                property bool moveUp: false
                property bool moveDown: false
                property bool moveLeft: false
                property bool moveRight: false
                property int direction: 90

                Behavior on x {
                    NumberAnimation {
                        duration: 100
                    }
                }

                Behavior on y {
                    NumberAnimation {
                        duration: 100
                    }
                }

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

                Behavior on x {
                    NumberAnimation {
                        duration: 100
                    }
                }

                Behavior on y {
                    NumberAnimation {
                        duration: 100
                    }
                }

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
