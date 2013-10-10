import QtQuick 2.0

Row{
    id: itemView
    Text{
        width: 10
        height: 10
        text: modelData.hasChild? modelData.isOpen ? "-" : "+" : ""
        MouseArea{
            anchors.fill: parent
            onClicked: modelData.isOpen = !modelData.isOpen;
        }
    }
    Column{
        Text{ text: modelData.content }
        Loader{
            source: modelData.isOpen ? "TreeItemsList.qml" : "Empty.qml"
        }
    }
}
