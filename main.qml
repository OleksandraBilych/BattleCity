import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import QtQml.Models 2.1

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

        if (aPlayer.moveUp && playerTank.coordinate_y - step > 0) {
            if (playerTank.direction != 0) {
                playerTank.direction = 0;
            } else {
                playerTank.coordinate_y -= step;
            }
        } else if (playerTank.coordinate_y < 0) {
            playerTank.coordinate_y = 0;
        }

        if (aPlayer.moveDown && playerTank.coordinate_y + step < limitY) {
            if (playerTank.direction != 180) {
                playerTank.direction = 180;
            } else {
                playerTank.coordinate_y += step;
            }
        } else if (playerTank.coordinate_y > limitY) {
            playerTank.coordinate_y = limitY;
        }

        if (aPlayer.moveLeft && playerTank.coordinate_x - step > 0) {
            if (playerTank.direction != 270) {
                playerTank.direction = 270;
            } else {
                playerTank.coordinate_x -= step;
            }
        } else if (playerTank.coordinate_x < 0) {
            playerTank.coordinate_x = 0;
        }

        if (aPlayer.moveRight && playerTank.coordinate_x + step < limixX) {
            if (playerTank.direction != 90) {
                playerTank.direction = 90;
            } else {
                playerTank.coordinate_x += step;
            }
        } else if (playerTank.coordinate_x > limixX) {
            playerTank.coordinate_x = limixX;
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
                x: playerTank.coordinate_x
                y: playerTank.coordinate_y
                width: 50
                height: 50
                rotation: playerTank.direction

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

            Repeater {
                model: gameBoard.enemies
                Enemy {
                    id: enemyTank
                    x: modelData.coordinate_x
                    y: modelData.coordinate_y
                    width: 50
                    height: 50
                    rotation: modelData.direction

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
                computer.animation = true;
            }
        }
    }
}
