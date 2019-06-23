QT += quick
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    src/TextProcessor.h

SOURCES += \
    src/text-processor.cpp \
    src/TextProcessor.cpp

RESOURCES += qml.qrc

QML_IMPORT_PATH = qml

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
