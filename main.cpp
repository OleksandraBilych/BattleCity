#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "boardobject.h"
#include "tank.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"


int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    Player* p = new Player(100, 20, "Sasha");
    Bullet* b = p->attack();
    delete p;

    Enemy* e = new Enemy(100, 15);
    delete e;

    return app.exec();
}
