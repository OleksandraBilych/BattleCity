#include "board.h"

Board::Board(QObject *parent) : QObject(parent) {
    qDebug() << "Constructor Board";

    Enemy *enemy = new Enemy(100, 20, dynamic_cast<QQuickItem *>(parent));
    enemy->setProperty("x", 50);
    enemy->setProperty("y", 50);

    m_enemies << enemy;

    emit enemiesChanged();
}

Board::~Board() {
//    if ( enemy != nullptr ) {
//        delete enemy;
//    }
}

QList<Enemy *> Board::getEnemies() {
    return m_enemies;
}

void Board::add()
{
    Enemy *enemy = new Enemy(100, 20, static_cast<QQuickItem *>(this->parent()));
    enemy->setProperty("x", 100);
    enemy->setProperty("y", 100);
    m_enemies.append(enemy);

    emit enemiesChanged();
}

void Board::append_enemy(QQmlListProperty<Enemy> *list, Enemy *value)
{
    QList<Enemy*> *enemies = static_cast<QList<Enemy*> *>(list->data);

    enemies->append(value);
}

QQmlListProperty<Enemy> Board::enemies()
{
    return QQmlListProperty<Enemy>(static_cast<QObject *>(this), static_cast<void *>(&m_enemies),
                                     &Board::append_enemy, 0, 0, 0);
}
