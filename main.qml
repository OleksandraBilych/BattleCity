import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import QtQml.Models 2.1
import QtQuick.Dialogs 1.2

import BattleCity 1.0

ApplicationWindow {
    id: mainWindow
    title: qsTr("Battle City")
    color: "gray"
    visible: true

    width: 850
    height: 850

    flags: Qt.SplashScreen

    Dialog {
        id: closeDialog
        visible: false
        title: "Do you want to exit the game?"
        standardButtons: StandardButton.Yes | StandardButton.No

        onYes: {
            console.log("Exit");
            visible = false;
            mainWindow.close();
        }

        onNo: {
            console.log("Return to game");
            visible = false;
            board.focus = true;
            computer.animation = true;
        }
    }

    Item {
        width: 750
        height: 750
        x: 50
        y: 50

        Rectangle {
            id: board
            visible: false
            focus: false
            width: 750
            height: 750
            color: "black"

            Keys.onPressed: {
                if (event.key == Qt.Key_Left ||
                    event.key == Qt.Key_Right ||
                    event.key == Qt.Key_Up ||
                    event.key == Qt.Key_Down) {

                tankAI.sendPressSignal(gameBoard, playerTank, event.key);
                } else if (event.key == Qt.Key_Escape) {
                    closeDialog.visible = false;
                    board.focus = false;
                    computer.animation = false;
                    closeDialog.visible = true;
                } else if (event.key == Qt.Key_Space) {
                    gameBoard.addBullet(playerTank.attack());
                }

                event.accepted = true;
            }

            Player {
                id: aPlayer
                x: playerTank.coordinate_x
                y: playerTank.coordinate_y
                width: playerTank.objectWidth
                height: playerTank.objectHeight
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
                    source: playerTank.imageURL
                }
            }

            PlayersBase {
                id: base
                x: playersBase.coordinate_x
                y: playersBase.coordinate_y
                width: playersBase.objectWidth
                height: playersBase.objectHeight
                rotation: playersBase.direction

                Image {
                    id: playersBaseBackground
                    anchors.fill: parent
                    source: playersBase.imageURL
                }
            }

            Repeater {
                model: gameBoard.enemies
                Enemy {
                    id: enemyTank
                    x: modelData.coordinate_x
                    y: modelData.coordinate_y
                    width: modelData.objectWidth
                    height: modelData.objectHeight
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
                        source: modelData.imageURL
                    }
                }
            }

            Repeater {
                model: gameBoard.bullets
                Bullet {
                    id: bullet
                    x: modelData.coordinate_x
                    y: modelData.coordinate_y
                    width: modelData.objectWidth
                    height: modelData.objectHeight
                    rotation: modelData.direction

                    Image {
                        id: bulletBackground
                        anchors.fill: parent
                        source: modelData.imageURL
                    }
                }
            }

            Repeater {
                model: gameBoard.walls
                Wall {
                    id: wall
                    x: modelData.coordinate_x
                    y: modelData.coordinate_y
                    width: modelData.objectWidth
                    height: modelData.objectHeight
                    rotation: modelData.direction

                    Image {
                        id: wallBackground
                        anchors.fill: parent
                        source: modelData.imageURL
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
