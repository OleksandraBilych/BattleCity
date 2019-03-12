#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QIcon>

#include "boardobject.h"
#include "board.h"
#include "tank.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "mainAI.h"
#include "wall.h"
#include "playersbase.h"
#include "globalvariables.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/appIcon.png"));

    qmlRegisterType<Board>("BattleCity", 1, 0, "Board");
    qmlRegisterType<BoardObject>();
    qmlRegisterType<Player>();
    qmlRegisterType<Enemy>();
    qmlRegisterType<Bullet>();
    qmlRegisterType<Wall>();
    qmlRegisterType<PlayersBase>();
    qmlRegisterType<Tank>();

    QQmlApplicationEngine engine;
    QScopedPointer<MainAI> comp(new MainAI(&app));

    engine.rootContext()->setContextProperty("computer", comp.data());
    engine.rootContext()->setContextProperty("tankAI", comp->getTankAI());
    engine.rootContext()->setContextProperty("gameBoard", comp->getBoard());
    engine.rootContext()->setContextProperty("playerTank", comp->getBoard()->getPlayer());
    engine.rootContext()->setContextProperty("playersBase", comp->getBoard()->getBase());

    engine.rootContext()->setContextProperty("globalVariables", &GlobalVariables::getInstance());

    engine.setContextForObject(comp->getBoard(), engine.rootContext());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

