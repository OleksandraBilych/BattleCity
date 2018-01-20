#include "bullet.h"

Bullet::Bullet(const Tank* attacker, QObject* parent)
    : attacker(attacker)
{
    qDebug() << "Constructor: Bullet";

    direction = attacker->getDirection();
    objectWidth = 10;
    objectHeight = 10;

    if ( direction == Direction::dir_down) {
        coordinate_x = attacker->getX() + (attacker->getWidth() - objectWidth) / 2;
        coordinate_y = attacker->getY() + attacker->getHeight();

    } else if (direction == Direction::dir_up) {
        coordinate_x = attacker->getX() + (attacker->getWidth() - objectWidth) / 2;
        coordinate_y = attacker->getY() - objectHeight;

    } else if (direction == Direction::dir_left) {
        coordinate_x = attacker->getX() -  attacker->getWidth() / 2;
        coordinate_y = attacker->getY() + (attacker->getHeight() - objectHeight) / 2;

    } else if (direction == Direction::dir_right) {
        coordinate_x = attacker->getX() + attacker->getWidth();
        coordinate_y = attacker->getY() + (attacker->getHeight() - objectHeight) / 2;
    }
}

Bullet::Bullet()
{
    qDebug() << "Default constructor: Bullet";
    attacker = nullptr;
}

Bullet::~Bullet()
{
    qDebug() << "Destructor: Bullet";
}

const Tank* Bullet::getAttacker() const
{
    return attacker;
}

void Bullet::setAttacker(const Tank* attacker)
{
    this->attacker = attacker;
}

void Bullet::move()
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

void Bullet::attack(Tank& enemy)
{
    qDebug() << "Attack enemy";

    if (attacker->getIsPlayer() == enemy.getIsPlayer())
        return;

    try {
        enemy.ensureIsAlive();

        float newEnemyHitPoint = enemy.getHitPoints() - attacker->getDamage();
        enemy.takeDamage(newEnemyHitPoint);

    } catch (TankIsDead& e) {
        qDebug() << &enemy << " is dead!";
    }
}
