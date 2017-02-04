#ifndef ENEMY_H
#define ENEMY_H

#include "tank.h"

class Enemy : public Tank {
public:
    Enemy(float hitPointsLimit, float damage, QObject* parent = 0);
    Enemy(QObject* parent = 0);
    virtual ~Enemy();

    virtual void rotate(Direction value);
    virtual void move(Direction value);
    virtual void attack(float value);
};

#endif // ENEMY_H
