#include "enemyAI.h"

EnemyAI::EnemyAI(QObject *parent) : QObject(parent)
{
    qDebug() << "Constructor enemy's artificial intelligence";
}

EnemyAI::~EnemyAI()
{

}

void EnemyAI::sendPressSignal(Board* board)
{
    for (auto& enemy : board->getEnemies()) {
        if (!(rand() % 20)) {
            enemy->updateDirection();
        }

        board->move(enemy);
    }
}
