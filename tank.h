#ifndef TANK_H
#define TANK_H

#include "boardobject.h"

class Tank : public BoardObject {
protected:
    float hitPoints;
    float hitPointsLimit;
    float damage;
    bool isDead;

public:
    explicit Tank();
    virtual ~Tank();

    float getDamage() const;
    float getHitPoints() const;
    float getHitPointsLimit() const;
    bool getIsDead() const;

    void setHitPoints(float value);
    void setHitPointsLimit(float value);
    void setDamage(float value);
    void setIsDead(bool value);

    virtual void rotate(Rotate value) = 0;
    virtual void attack(float value) = 0;
    void takeDamage(float value);
};

#endif // TANK_H
