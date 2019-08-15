import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3
//import QtCharts 2.13

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Expert System")

    color: "beige";

    SplitView {
        id: appSplitView
        anchors.fill: parent

        width: parent.width
        height: parent.height

        MainTableColumn {
            SplitView.preferredWidth: 100
        }

        MainTabView {}

    }
}
