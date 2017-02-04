#include "bullet.h"

Bullet::Bullet(const Tank& attacker, QObject* parent):
    attacker(&attacker) {
    direction = attacker.getDirection();
    qDebug() << "Constructor: Bullet";
}

Bullet::~Bullet() {
    qDebug() << "Destructor: Bullet";
}

const Tank* Bullet::getAttacker() const {
    return attacker;
}

const Tank* Bullet::getEnemy() const {
    return enemy;
}

void Bullet::setAttacker(const Tank& attacker) {
    this->attacker = &attacker;
}

void Bullet::setEnemy(const Tank& enemy) {
    this->enemy = &enemy;
}

void Bullet::move(Direction value) {

}

void Bullet::attack() {
    qDebug() << "Attack enemy";
}
