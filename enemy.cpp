#include "enemy.h"

Enemy::Enemy(float hitPointsLimit, float damage, QQuickItem* parent) :
    Tank(parent) {
    qDebug() << "Constructor: Enemy";

    this->hitPointsLimit = hitPointsLimit;
    this->damage = damage;
    hitPoints = hitPointsLimit;
    direction = Direction::dir_down;
    coordinate_x = 300;
    coordinate_y = 20;
}

Enemy::Enemy(QQuickItem* parent) :
    Tank(parent) {
    qDebug() << "Constructor: Enemy";

    this->hitPointsLimit = 150;
    this->damage = 50;
    hitPoints = 150;
    direction = Direction::dir_down;
    coordinate_x = 300;
    coordinate_y = 20;
}

Enemy::~Enemy() {
    qDebug() << "Destructor: Enemy";
}

void Enemy::rotate(int value) {

}


