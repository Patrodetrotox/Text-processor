import QtQuick 2.6
import QtQuick.Controls 2.2
import "pages"

ApplicationWindow {
    title: qsTr("Text Processor")
    width: 360; height: 640
    visible: true

    TextProcessorPage {
        anchors.fill: parent
    }
}
