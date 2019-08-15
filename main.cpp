//#include <QGuiApplication>
#include <QApplication>
#include "appcontroller.h"

//#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);
    QApplication app(argc, argv);

    AppController appController;

    if (!appController.initialize())
        return -1;

/*
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
*/
    return app.exec();
}
