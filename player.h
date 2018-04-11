#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"
#include <string>

class Player : public Tank
{
    Q_OBJECT

public:
    Player(float hitPointsLimit, float damage, const std::string& name,
           int coordinate_x, int coordinate_y, QQuickItem* parent = 0);
    Player();

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    virtual ~Player();

    const std::string& getName() const;
    const short getNumberOfDeadTanks() const;

    void setName(const std::string& value);

    virtual void rotate(int value);
    void move();
    Q_INVOKABLE void rotatePlayer();
    void incrementNumberOfDeadTanks();

private:
    std::string name;
    short numberOfDeadTanks;
};

#endif // PLAYER_H


