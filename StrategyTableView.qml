import QtQuick 2.13
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import StrategyTableModel 1.0

Item {
    TableView {
      //  id: strategyTableView
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        clip: true

        property double rowHeight: 70
        columnWidthProvider: function (column) {
        /*    swicth (column) {
                case 1:
                    return 100;
                case 2:
                    return 150;
                default:
                    return 50;
            } */

            return 300
        }
        model: StrategyTableModel {}
        delegate: RowLayout {
            spacing: 0

            Label {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredHeight: implicitHeight * 1.5
                Layout.minimumWidth: 300
                anchors.centerIn: parent
                background: Rectangle { border.color: "red" }
                text: strategyId
            }

            Label {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredHeight: implicitHeight * 1.5
                Layout.minimumWidth: 300
                background: Rectangle { border.color: "green" }
                text: strategyName
            }


        }

        // Headers for tableView
        Rectangle { // mask the headers
            z: 3
            y: strategyTableView.contentY
            x: strategyTableView.contentX
            width: strategyTableView.leftMargin
            height: strategyTableView.topMargin
        }

        Row {
            id: columnsHeader
            y: strategyTableView.contentY
            z: 2
            Repeater {
                model: 2
                Label {
                    width: strategyTableView.columnWidthProvider(modelData)
                    height: 35
                    text: "Column" + modelData
                    color: "white"
                    font.pixelSize: 20
                    padding: 10
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment : Text.AlignHCenter
                    background: Rectangle { color: "#333333" }
                }
            }
        }

    }

}
