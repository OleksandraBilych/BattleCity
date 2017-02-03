#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"

class Player : public Tank {
private:
    std::string name;

public:
    Player();
    virtual ~Player();

    const std::string& getName() const;

    void setName(const std::string& value);
};

#endif // PLAYER_H
