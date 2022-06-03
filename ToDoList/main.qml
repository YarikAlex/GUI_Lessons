import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 480
    height: 640
    visible: true
    title: qsTr("ToDoList")
    id: root

    Rectangle {
        id: canvas
        anchors.fill: parent
        color: "black"

        Rectangle{
            id: setTask
            width: parent.width
            height: 50
            visible: false
            color: "grey"
            anchors.bottom: rec2.top

            TextEdit {
                id: info
                text: "Enter text"
                font.family: "Monotype"
                color: "white"
                font.pointSize: 10
                focus: true
            }
            Button{
                id: addTask
                width: 30
                height: 30
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                text: "Add"
                property int num: 0
                onClicked: {
                   const newTask = Qt.createQmlObject("import QtQuick 2.15
                                                        Rectangle {
                                                            width: 480;
                                                            height: 50;
                                                            color: '#1c1c1c';
                                                            anchors.top: parent.top" + num +";
                                                            }", canvas, )
                   num + 50
                }
            }
        }

        Rectangle{
            id:rec1
            color: "#1C1C1C"
            anchors.bottom: canvas.bottom
            width: parent.width
            height: 50
            radius: 5
        }

        Rectangle {
            id: rec2
            color: "darkred"
            width: 50
            height: 50
            radius: 25
            anchors.centerIn: rec1
            TextEdit {
                text: "+"
                font.family: "Helvetica"
                font.pointSize: 14
                color: "black"
                anchors.centerIn: parent
            }
        }
        Button{
            id: btnAdd
            flat: true
            width: 50
            height: 50
            anchors.centerIn: rec2
            onClicked: setTask.visible = true
        }
    }
}
