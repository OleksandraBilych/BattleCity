#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"
#include <string>

class Player : public Tank
{
    Q_OBJECT

public:
    Player(float hitPointsLimit, float damage, const std::string& name, QQuickItem* parent = 0);
    Player(QQuickItem* parent = 0);
    virtual ~Player();

    const std::string& getName() const;

    void setName(const std::string& value);

    virtual void rotate(int value);
    void move();

private:
    std::string name;
};

#endif // PLAYER_H


