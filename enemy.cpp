#include "enemy.h"

Enemy::Enemy(float hitPointsLimit, float damage, QObject* parent) {
    qDebug() << "Constructor: Enemy";

    this->hitPointsLimit = hitPointsLimit;
    this->damage = damage;
    hitPoints = hitPointsLimit;
    direction = Direction::dir_down;
}

Enemy::~Enemy() {
    qDebug() << "Destructor: Enemy";
}

void Enemy::rotate(Direction value) {

}

void Enemy::move(Direction value) {

}


