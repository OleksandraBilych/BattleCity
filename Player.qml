import QtQuick 2.0

Item {
    id: player
    x: 100
    y: 150
    //anchors.bottom: parent.bottom
    //anchors.horizontalCenter: parent.horizontalCenter

    Image {
        id: tileBackground
        width: 50
        height: 50
        source: "qrc:/images/player.png"
        rotation: 90
    }
}
