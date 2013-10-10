import QtQuick 2.0

Rectangle {
    width: 360
    height: 360
    ListView{
        anchors.fill: parent
        model: programmModel.tree
        delegate: ItemView{}
    }
}
