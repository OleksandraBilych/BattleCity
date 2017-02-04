#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"
#include <string>

class Player : public Tank {
private:
    std::string name;

public:
    Player(float hitPointsLimit, float damage, const std::string& name, QObject* parent = 0);
    virtual ~Player();

    const std::string& getName() const;

    void setName(const std::string& value);

    virtual void rotate(Direction value);
    virtual void move(Direction value);
};

#endif // PLAYER_H
