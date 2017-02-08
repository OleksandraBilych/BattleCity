#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "player.h"
#include "enemy.h"
#include "computer.h"

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Computer* comp = new Computer(&app);
    engine.rootContext()->setContextProperty("computer", comp);
    engine.rootContext()->setContextProperty("enemyTank", (comp->getBoard()->getEnemy()));

    Player* player = new Player(100, 20, "PlayerTank");
    engine.rootContext()->setContextProperty("playerTank", player);

    qmlRegisterType<Player>("BattleCity", 1, 0, "Player");
    qmlRegisterType<Enemy>("BattleCity", 1, 0, "Enemy");

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}

