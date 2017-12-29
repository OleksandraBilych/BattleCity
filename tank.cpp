#include "tank.h"
#include "bullet.h"

Tank::Tank(QQuickItem *parent) : BoardObject(parent)
{
    qDebug() << "Constructor: Tank";

    isDead = false;
    isPlayer = false;

    objectWidth = 50; // TO DO: create common config
    objectHeight = 50;
}

Tank::~Tank()
{
    qDebug() << "Destructor: Tank";
}

float Tank::getDamage() const
{
    return damage;
}

float Tank::getHitPoints() const
{
    return hitPoints;
}

float Tank::getHitPointsLimit() const
{
    return hitPointsLimit;
}

bool Tank::getIsDead() const
{
    return isDead;
}

bool Tank::getIsPlayer() const
{
    return isPlayer;
}

void Tank::setHitPoints(float value)
{
    hitPoints = value;
}

void Tank::setHitPointsLimit(float value)
{
    hitPointsLimit = value;
}

void Tank::setDamage(float value)
{
    damage = value;
}

void Tank::setIsDead(bool value)
{
    isDead = value;
}

void Tank::ensureIsAlive()
{
    if (isDead)
        throw TankIsDead();
}

void Tank::takeDamage(float value)
{
    if ( value < 0 ) {
        hitPoints = 0;
        isDead = true;
    } else
        hitPoints = value;
}

Bullet* Tank::attack()
{
    return new Bullet(this);
}

