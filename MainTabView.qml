import QtQuick 2.13
import QtQuick.Controls 1.4

Item {
    TabView {
        anchors.fill: parent

        Tab {
            title: "Home"
            HomeTab {}
        }
    }
}
