#include "enemy.h"

Enemy::Enemy(float hitPointsLimit, float damage, QObject* parent) {
    qDebug() << "Constructor: Enemy";

    this->hitPointsLimit = hitPointsLimit;
    this->damage = damage;
    hitPoints = hitPointsLimit;
    direction = Rotate::rotate_down;
    qDebug() << direction;
}

Enemy::~Enemy() {
    qDebug() << "Destructor: Enemy";
}

void Enemy::rotate(Rotate value) {

}

void Enemy::attack(float value) {

}
