#include "board.h"

Board::Board(QObject *parent) : QObject(parent) {
    qDebug() << "Constructor Board";

    for (int i = 0; i < 5; i++) {
        m_enemies.append(new Enemy(100, 20));
        m_enemies.at(i)->setProperty("coordinate_x", 100 * (i + 1));
    }
}

Board::~Board() {
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

