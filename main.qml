import QtQuick 2.0

import QtQml.Models 2.3
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2

import BattleCity 1.0

ApplicationWindow {
    id: mainWindow
    title: qsTr("Battle City")
    color: "black"
    visible: true
    width: 850
    height: 850
    modality: "WindowModal"

    flags: Qt.SplashScreen

    Item {
        focus: true
        Keys.onEscapePressed: {
          mainWindow.close()
        }
    }

    Dialog {
        id: endDialog
        visible: false
        title: "GAME OVER !!!"
        objectName: "endDialog"
    }

    Dialog {
        id: closeDialog
        visible: false
        title: "Do you want to exit the game?"
        standardButtons: StandardButton.Yes | StandardButton.No

        onYes: {
            visible = false;
            mainWindow.close();
        }

        onNo: {
            visible = false;
            board.focus = true;
            computer.animation = true;
        }
    }

    Rectangle {
            id: startDialog
            width: mainWindow.width
            height: 300
            y: (mainWindow.height - height) / 2
            visible: true
            color: "#090808"

            Image {
                id: title
                anchors.horizontalCenter: parent.horizontalCenter
                y: 20
                source: "qrc:/images/title.png"
            }

            Button {
                id: startButton
                anchors.horizontalCenter: parent.horizontalCenter
                y: title.height + 50
                width: startTitle.width + 10
                height: startTitle.height + 10

                background: Rectangle {
                            color: "black"
                            border.width: focus ? 5 : 1
                            border.color: "#888"
                            radius: 4
                        }

                Text {
                    id: startTitle
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Start game")
                    color: "white"
                    font.bold: true
                    font.pointSize: 20
                }

                onClicked: {
                    startDialog.visible = false;
                    board.visible = true;
                    board.focus = true;
                    computer.animation = true;
                    mainWindow.color = "gray"
                }
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                y: startDialog.height - 50
                text: "For exit press - ESC"
                font.pointSize: 14
                font.bold: true
                color: "white"
            }
    }

    Item {
        width: 750
        height: 750
        x: 50
        y: 50
        objectName: "mainScreen"

        Rectangle {
            id: board
            visible: false
            focus: false
            width: 750
            height: 750
            color: "black"
            objectName: "board"

            Keys.onPressed: {
                if (event.key == Qt.Key_Left ||
                    event.key == Qt.Key_Right ||
                    event.key == Qt.Key_Up ||
                    event.key == Qt.Key_Down) {
                tankAI.sendPressSignal(gameBoard, playerTank, event.key);
                } else if (event.key == Qt.Key_Space) {
                    gameBoard.addBullet(playerTank.attack());
                }
            }

            Keys.onEscapePressed: {
                board.focus = false;
                computer.animation = false;
                closeDialog.visible = true;
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
                        source:  modelData.imageURL
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

        Text {
            id: gameOver
            x: 315
            visible: false
            objectName: "gameOver"

            text: qsTr("GAME" + "\n" + "OVER")
            color: "red"
            font.bold: true
            font.pointSize: 30
            horizontalAlignment: Text.Center

            NumberAnimation on y {
                from: 750;
                to: 350;
                duration: 4000;
                running: gameOver.visible === true ? true : false}
            }
        }
}
