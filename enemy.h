#ifndef ENEMY_H
#define ENEMY_H

#include "tank.h"

class Enemy : public Tank {
public:
    Enemy();
    virtual ~Enemy();

    virtual void rotate(Rotate value);
    virtual void attack(float value);
};

#endif // ENEMY_H
