# pragma once

#include "tank.h"

class EndOfBoardException {};

class Enemy : public Tank
{
    Q_OBJECT

public:
    Enemy(float hitPointsLimit, float damage,
          int coordinate_x, int coordinate_y, QObject* parent = nullptr);

    Enemy(const Enemy&) = delete;
    Enemy& operator=(const Enemy&) = delete;

    virtual ~Enemy();

    virtual void rotate(int value);
    void move();
};
