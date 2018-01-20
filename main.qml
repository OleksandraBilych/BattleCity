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
    color: "black"
    visible: true

    width: Screen.width
    height: Screen.height

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
        Rectangle {
            id: board
            width: 650
            height: 650
            visible: false
            focus: false
            color: "black"

            Keys.onPressed: {
                if (event.key == Qt.Key_Left ||
                    event.key == Qt.Key_Right ||
                    event.key == Qt.Key_Up ||
                    event.key == Qt.Key_Down) {

                gameBoard.move(playerTank, event.key);

                } else if (event.key == Qt.Key_Escape) {
                    closeDialog.visible = false;
                    board.focus = false;
                    computer.animation = false;
                    closeDialog.visible = true;
                }
                else if (event.key == Qt.Key_Space) {
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
                    source: "qrc:/images/player.png"
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
                        source: "qrc:/images/enemy.png"
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
                        source: "qrc:/images/bullet10*10.png"
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
