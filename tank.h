#ifndef TANK_H
#define TANK_H

#include "boardobject.h"
#include "bullet.h"

class Bullet;
class TankIsDead {};

class Tank : public BoardObject
{
    Q_OBJECT

public:
    explicit Tank(QQuickItem *parent = 0);
    virtual ~Tank();

    float getDamage() const;
    float getHitPoints() const;
    float getHitPointsLimit() const;
    bool getIsPlayer() const;


    void setHitPoints(float value);
    void setHitPointsLimit(float value);
    void setDamage(float value);

    void ensureIsAlive();

    virtual void rotate(int value) = 0;
    virtual void move() = 0;
    Q_INVOKABLE virtual Bullet* attack();
    void takeDamage(float value);

protected:
    float hitPoints;
    float hitPointsLimit;
    float damage;
    bool isPlayer;
};

#endif // TANK_H
