import QtQuick 2.7

Page1Form {

    button1.onClicked: {
        console.log("Start");
        button1.visible = false;
    }
}
