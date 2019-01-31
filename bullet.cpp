#include "bullet.h"
#include "constants.h"

Bullet::Bullet(Tank* attacker, QObject* parent)
    : attacker(attacker), BoardObject(parent)
{
    qDebug() << "Constructor: Bullet";

    direction = attacker->getDirection();
    objectWidth = bulletWidth;
    objectHeight = bulletHeight;
    imageURL = "qrc:/images/bullet10*10.png";

    if ( direction == Direction::dir_down) {
        coordinate_x = attacker->getX() + (attacker->getWidth() - objectWidth) / 2;
        coordinate_y = attacker->getY() + attacker->getHeight();

    } else if (direction == Direction::dir_up) {
        coordinate_x = attacker->getX() + (attacker->getWidth() - objectWidth) / 2;
        coordinate_y = attacker->getY() - objectHeight;

    } else if (direction == Direction::dir_left) {
        coordinate_x = attacker->getX() - objectWidth;
        coordinate_y = attacker->getY() + (attacker->getHeight() - objectHeight) / 2;

    } else if (direction == Direction::dir_right) {
        coordinate_x = attacker->getX() + attacker->getWidth();
        coordinate_y = attacker->getY() + (attacker->getHeight() - objectHeight) / 2;
    }
}

Bullet::~Bullet()
{
    qDebug() << "Destructor: Bullet";
}

Tank* Bullet::getAttacker() const
{
    return attacker;
}

void Bullet::setAttacker(Tank* attacker)
{
    this->attacker = attacker;
}

void Bullet::move()
{
    if ( direction == Direction::dir_down) {
        coordinate_y += cellSize;
        emit YChanged(coordinate_y);

    } else if (direction == Direction::dir_up) {
        coordinate_y -= cellSize;
        emit YChanged(coordinate_y);

    } else if (direction == Direction::dir_left) {
        coordinate_x -= cellSize;
        emit XChanged(coordinate_x);

    } else if (direction == Direction::dir_right) {
        coordinate_x += cellSize;
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
        qDebug() << &enemy << " was attacked!" << newEnemyHitPoint;
        enemy.takeDamage(newEnemyHitPoint);

    } catch (TankIsDead& e) {
        qDebug() << &enemy << " is dead!";
    }
}
