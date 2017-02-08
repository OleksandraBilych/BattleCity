#ifndef ENEMY_H
#define ENEMY_H

#include "tank.h"

class EndOfBoardException {};

class Enemy : public Tank {
    Q_OBJECT

public:
    Enemy(float hitPointsLimit, float damage, QQuickItem* parent = 0);
    Enemy(QQuickItem* parent = 0);
    virtual ~Enemy();

    void move();
    void doStep();
};

#endif // ENEMY_H
