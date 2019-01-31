#ifndef ENEMY_H
#define ENEMY_H

#include "tank.h"

class EndOfBoardException {};

class Enemy : public Tank
{
    Q_OBJECT

public:
    Enemy(float hitPointsLimit, float damage,
          int coordinate_x, int coordinate_y, QObject* parent = 0);
    Enemy();

    Enemy(const Enemy&) = delete;
    Enemy& operator=(const Enemy&) = delete;

    virtual ~Enemy();

    virtual void rotate(int value);
    void move();
};

#endif // ENEMY_H
