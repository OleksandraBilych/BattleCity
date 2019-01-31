#include <QGuiApplication>
#include <QWindow>

#include "enemy.h"
#include "constants.h"

Enemy::Enemy(float hitPointsLimit, float damage,
             int coordinate_x, int coordinate_y, QObject* parent)
    : Tank(parent)
{
    qDebug() << "Constructor: Enemy";

    this->hitPointsLimit = hitPointsLimit;
    this->damage = damage;
    hitPoints = hitPointsLimit;
    direction = Direction::dir_down;
    this->coordinate_x = coordinate_x;
    this->coordinate_y = coordinate_y;
    imageURL = "qrc:/images/enemy.png";
}

Enemy::~Enemy()
{
    qDebug() << "Destructor: Enemy";
}

void Enemy::rotate(int value)
{

}

void Enemy::move()
{
    if (direction == Direction::dir_down) {
        coordinate_y += cellSize;
        emit YChanged(coordinate_y);

    } else if (direction == Direction::dir_up) {
        coordinate_y -= cellSize;
        emit YChanged(coordinate_y);

    } else if (direction == Direction::dir_left) {
        coordinate_x -= cellSize;
        emit XChanged(coordinate_x);

    } else if (direction == Direction::dir_right) {
        coordinate_x += cellSize;
        emit XChanged(coordinate_x);
    }
}

