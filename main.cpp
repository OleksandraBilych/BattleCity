#include <QGuiApplication>
#include <QQmlContext>
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

    Player* player = new Player(100, 20, "Sasha");
    engine.rootContext()->setContextProperty("sasha", player);

    Enemy* enemy = new Enemy(100, 20);
    engine.rootContext()->setContextProperty("sirius", enemy);

    qmlRegisterType<Player>("BattleCity", 1, 0, "Player");
    qmlRegisterType<Enemy>("BattleCity", 1, 0, "Enemy");
    qmlRegisterType<Tank>();
    qmlRegisterType<Bullet>();
    qmlRegisterType<BoardObject>();

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}

