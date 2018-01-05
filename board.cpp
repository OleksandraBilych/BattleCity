#include "board.h"
#include <QGuiApplication>
#include <QScreen>

Board::Board(QObject *parent) : QObject(parent)
{
    qDebug() << "Constructor Board";

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    int enemiesAmount = 6; // TO DO: move to commmon config
    int distance = width/enemiesAmount;

    for (int i = 0; i < enemiesAmount; i++) {
        m_enemies.append(new Enemy(100, 20, distance * i + distance / 2, 0));
    }

    player = new Player(100, 20, "PlayerTank", width / 2, height);
}

Board::~Board()
{
    m_enemies.clear();
}

QQmlListProperty<Enemy> Board::enemies()
{
    return QQmlListProperty<Enemy>(this, m_enemies);
}

QList<Enemy*> Board::getEnemies()
{
    return m_enemies;
}

Player* Board::getPlayer() const
{
    return player;
}

