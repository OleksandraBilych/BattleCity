#ifndef ENEMY_H
#define ENEMY_H

#include "tank.h"

class Enemy : public Tank {
    Q_OBJECT
public:
    Enemy(float hitPointsLimit, float damage, QQuickItem* parent = 0);
    Enemy(QQuickItem* parent = 0);
    virtual ~Enemy();

    virtual void rotate(int value);
};

#endif // ENEMY_H
