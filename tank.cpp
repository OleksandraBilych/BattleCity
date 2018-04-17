#include "tank.h"
#include "bullet.h"
#include "constants.h"

Tank::Tank(QQuickItem *parent) : BoardObject(parent)
{
    isPlayer = false;

    objectWidth = tankWidth;
    objectHeight = tankHeight;

    imageURL = "qrc:/images/player.png";
}

Tank::~Tank()
{

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

void Tank::ensureIsAlive()
{
    if (isDead)
        throw TankIsDead();
}

void Tank::takeDamage(float value)
{
    if ( value <= 0 ) {
        hitPoints = 0;
        setIsDead(true);
        setImageURL("qrc:/images/blowTank75.png");
    } else
        hitPoints = value;
}


Bullet* Tank::attack()
{
    return new Bullet(this);
}

