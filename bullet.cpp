#include "bullet.h"

Bullet::Bullet(Tank* attacker, QObject* parent):
    attacker(attacker) {
    direction = attacker->getDirection();
    qDebug() << "Constructor: Bullet";
}

Bullet::~Bullet() {
    qDebug() << "Destructor: Bullet";
}

Tank* Bullet::getAttacker() const {
    return attacker;
}

void Bullet::setAttacker(Tank* attacker) {
    this->attacker = attacker;
}

void Bullet::move() {

}

void Bullet::attack(Tank& enemy) {
    qDebug() << "Attack enemy";

    if ( attacker->getIsPlayer() == enemy.getIsPlayer() ) {
        return;
    }

    try {
        enemy.ensureIsAlive();

        float newEnemyHitPoint = enemy.getHitPoints() - attacker->getDamage();
        enemy.takeDamage(newEnemyHitPoint);

    } catch ( TankIsDead& e ) {
        qDebug() << &enemy << " is dead!";
    }
}
