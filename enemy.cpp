#include "enemy.h"

Enemy::Enemy(float hitPointsLimit, float damage, QObject* parent) {
    qDebug() << "Constructor: Enemy";

    this->hitPointsLimit = hitPointsLimit;
    this->damage = damage;
    hitPoints = hitPointsLimit;
    direction = Rotate::rotate_down;
    qDebug() << direction;
}

//Enemy::Enemy(QObject* parent) :
//    Tank(parent, 100, 20),
//    direction(down)
//{
//    qDebug() << "Default constructor: Enemy";
//}

Enemy::~Enemy() {
    qDebug() << "Constructor: Enemy";
}

void Enemy::rotate(Rotate value) {

}

void Enemy::attack(float value) {

}
