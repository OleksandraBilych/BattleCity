# pragma once

#include "tank.h"
#include <string>

class Player : public Tank
{
    Q_OBJECT
    Q_PROPERTY(short deadTanks READ getDeadTanks WRITE setDeadTanks NOTIFY deadTanksChanged)

public:
    Player(float hitPointsLimit, float damage, const std::string& name,
           int coordinate_x, int coordinate_y, QObject* parent = nullptr);

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    virtual ~Player();

    const std::string& getName() const;
    Q_INVOKABLE short getDeadTanks() const;

    void setName(const std::string& value);
    void setDeadTanks(short value);

    virtual void rotate(int value);
    void move();
    Q_INVOKABLE void rotatePlayer();
    void incrementNumberOfDeadTanks();

signals:
    void deadTanksChanged(short value);

private:
    std::string name;
    short deadTanks;
};
