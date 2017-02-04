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

    qmlRegisterType<Player>();

    Player* player = new Player(100, 20, "Sasha", &app);
    engine.rootContext()->setContextProperty("player", player);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

//    Player* player = new Player(100, 20, "Sasha");
//    Enemy* enemy1 = new Enemy(100, 15);
//    Enemy* enemy2 = new Enemy(100, 15);

//    Bullet* playerBullet = player->attack();
//    Bullet* enemyBullet = enemy1->attack();

//    playerBullet->attack(*enemy2);
//    enemyBullet->attack(*enemy2);
//    enemyBullet->attack(*player);

//    delete player;
//    delete enemy1;
//    delete enemy2;

    return app.exec();
}

