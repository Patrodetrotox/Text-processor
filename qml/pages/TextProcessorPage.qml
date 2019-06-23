import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import Text.Processor 1.0

Page {
    id: page
    title: qsTr("Text Processor")

    TextProcessor {
        id: textProcessor
        action: actionSelector.action
        onTextChanged: if (textField.text !== text) textField.text = text
    }
    Pane {
        anchors.fill: parent

        GridLayout {
            anchors.fill: parent
            columns: 2

            Label {
                text: qsTr("Text to process");
                Layout.columnSpan: 2
            }
            TextArea {
                id: textField

                placeholderText: qsTr("Input text to process")
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.columnSpan: 2

                onTextChanged: if (textProcessor.text !== text) textProcessor.text = text
            }
            Label {
                text: qsTr("Action");
            }
            ComboBox {
                id: actionSelector

                readonly property int action: [
                    TextProcessor.NoAction,
                    TextProcessor.MakeUppercase,
                    TextProcessor.MakeLowercase
                ][currentIndex]

                model: [ qsTr("No action"), qsTr("Make uppercase"), qsTr("Make lowercase") ]
                Layout.fillWidth: true
            }
            Label {
                text: qsTr("Processed text")
                Layout.columnSpan: 2
            }
            TextArea {
                text: textProcessor.processedText
                readOnly: true
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.columnSpan: 2
            }
            Label {
                text: qsTr("Text to prepend")
            }
            TextField {
                id: prependTextField
                placeholderText: qsTr("Input text to prepend")
                Layout.fillWidth: true
            }
            Button {
                text: qsTr("Prepend")
                Layout.columnSpan: 2
                Layout.fillWidth: true

                onClicked: textProcessor.prepend(prependTextField.text)
            }
        }
    }
}
