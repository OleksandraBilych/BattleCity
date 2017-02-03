#include "tank.h"

Tank::Tank() {
    qDebug() << "Constructor: Tank";
}

Tank::~Tank() {
    qDebug() << "Destructor: Tank";
}

float Tank::getDamage() const {
    return damage;
}

float Tank::getHitPoints() const {
    return hitPoints;
}

float Tank::getHitPointsLimit() const {
    return hitPointsLimit;
}

bool Tank::getIsDead() const {
    return isDead;
}

void Tank::setHitPoints(float value) {
    hitPoints = value;
}

void Tank::setHitPointsLimit(float value) {
    hitPointsLimit = value;
}

void Tank::setDamage(float value) {
    damage = value;
}

void Tank::setIsDead(bool value) {
    isDead = value;
}

void Tank::takeDamage(float value) {

}
