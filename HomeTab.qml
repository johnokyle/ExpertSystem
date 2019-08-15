import QtQuick 2.13
//import QtQuick.Window 2.13
//import QtQuick.Controls 2.13
//import QtQuick.Layouts 1.3
import QtCharts 2.13

Item {
    id: homeTab
    anchors.fill: parent

    ChartView {
        title: "Line"
        anchors.fill: parent
        antialiasing: true

        LineSeries {
            name: "LineSeries2"
            XYPoint { x: 0; y: 0 }
            XYPoint { x: 0.1; y: 1.1 }
            XYPoint { x: 4.9; y: 5.0 }
        }

        LineSeries {
            name: "LineSeries"
            XYPoint { x: 0; y: 0 }
            XYPoint { x: 1.1; y: 2.1 }
            XYPoint { x: 1.9; y: 3.3 }
            XYPoint { x: 2.1; y: 2.1 }
            XYPoint { x: 2.9; y: 4.9 }
            XYPoint { x: 3.4; y: 3.0 }
            XYPoint { x: 4.1; y: 3.3 }
        }
    }


}
