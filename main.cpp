#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "tank.h"
#include "player.h"
#include "enemy.h"


int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));



    Player* p = new Player();
    delete p;

    Enemy* e = new Enemy();
    delete e;

    return app.exec();
}
