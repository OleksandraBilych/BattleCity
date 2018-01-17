#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "boardobject.h"
#include "board.h"
#include "tank.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "computer.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<Player>("BattleCity", 1, 0, "Player");
    qmlRegisterType<Board>("BattleCity", 1, 0, "Board");
    qmlRegisterType<Enemy>("BattleCity", 1, 0, "Enemy");
    qmlRegisterType<Bullet>("BattleCity", 1, 0, "Bullet");
    qmlRegisterType<Tank>();
    qmlRegisterType<BoardObject>();

    QQmlApplicationEngine engine;

    QScopedPointer<Computer> comp(new Computer(&app));
    engine.rootContext()->setContextProperty("computer", comp.data());

    engine.rootContext()->setContextProperty("gameBoard", comp->getBoard());
    engine.rootContext()->setContextProperty("playerTank", comp->getBoard()->getPlayer());

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}

