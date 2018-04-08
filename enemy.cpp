#include "enemy.h"
#include <QGuiApplication>
#include <QWindow>

Enemy::Enemy(float hitPointsLimit, float damage,
             int coordinate_x, int coordinate_y, QQuickItem* parent)
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

Enemy::Enemy()
{
    qDebug() << "Default constructor: Enemy";
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
    if ( direction == Direction::dir_down) {
        coordinate_y += 10;
        emit YChanged(coordinate_y);

    } else if (direction == Direction::dir_up) {
        coordinate_y -= 10;
        emit YChanged(coordinate_y);

    } else if (direction == Direction::dir_left) {
        coordinate_x -= 10;
        emit XChanged(coordinate_x);

    } else if (direction == Direction::dir_right) {
        coordinate_x += 10;
        emit XChanged(coordinate_x);
    }
}

