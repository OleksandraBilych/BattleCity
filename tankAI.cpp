#include "tankAI.h"

TankAI::TankAI(QObject *parent) : QObject(parent)
{
    qDebug() << "Constructor enemy's artificial intelligence";
}

TankAI::~TankAI()
{

}

void TankAI::sendPressSignal(Board* board)
{
    for (auto& enemy : board->getEnemies()) {
        if (!(rand() % 20)) {
            enemy->updateDirection();
        }

        Objects collisionObject = board->move(enemy);
        if (collisionObject == Objects::emptyCell)
            enemy->move();
        else
            enemy->updateDirection();
    }
}

void TankAI::sendPressSignal(Board* board, Tank* tank, Qt::Key keyDirection)
{
    // if we get direction we need firstly to check
    // do we must update direction to new one
    if (keyDirection != Qt::Key_unknown) {
        if ( keyDirection == Qt::Key_Down &&
             tank->getDirection() != Direction::dir_down) {
            tank->updateDirection(Direction::dir_down);

        } else if (keyDirection == Qt::Key_Up &&
                   tank->getDirection() != Direction::dir_up) {
            tank->updateDirection(Direction::dir_up);

        } else if (keyDirection == Qt::Key_Left &&
                   tank->getDirection() != Direction::dir_left) {
            tank->updateDirection(Direction::dir_left);

        } else if (keyDirection == Qt::Key_Right &&
                   tank->getDirection() != Direction::dir_right) {
            tank->updateDirection(Direction::dir_right);
        }
    }

    Objects collisionObject = board->move(tank);
    if (collisionObject == Objects::emptyCell)
        tank->move();
}

void TankAI::sendAtackSignal(Board* board)
{
    QList<Enemy*> enemies = board->getEnemies();
    int index = rand() % enemies.size();

    Enemy* enemy = enemies.at(index);
    board->addBullet(enemy->attack());
}
