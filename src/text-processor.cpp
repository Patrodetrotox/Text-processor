#include <QtQuick>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "TextProcessor.h"

int main(int argc, char *argv[]) {
    // ToDo: export TextProcessor class to QML --
    qmlRegisterType<TextProcessor>("Text.Processor", 1, 0, "TextProcessor");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/text-processor.qml")));
    if (engine.rootObjects().isEmpty()) return -1;
    return app.exec();
}
