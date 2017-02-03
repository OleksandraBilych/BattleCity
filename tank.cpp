#include "tank.h"

Tank::Tank(QObject *parent) : QObject(parent) {
    qDebug() << "Constructor: Tank";
}

Tank::~Tank() {
    qDebug() << "Destructor: Tank";
}

float Tank::getDamage() const {

}

float Tank::getHitPoints() const {

}

float Tank::getHitPointsLimit() const {

}

bool Tank::getIsDead() const {

}

void Tank::setHitPoints(float value) {

}

void Tank::setHitPointsLimit(float value) {

}

void Tank::setDamage(float value) {

}

void Tank::setIsDead() {

}

void Tank::rotate(Rotate value) {

}

void Tank::attack(float value) {

}

void Tank::takeDamage(float value) {

}
