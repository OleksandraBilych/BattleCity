#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "tank.h"
#include "player.h"

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    Tank* t = new Tank();
    delete t;

    Tank* p = new Player();
    delete p;

    return app.exec();
}
