import QtQuick 2.0

Rectangle {
    width: 360
    height: 360
    ListView{
        anchors.fill: parent
        model: programmModel.tree
        delegate: Row{
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
    }
}
