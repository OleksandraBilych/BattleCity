#ifndef BULLET_H
#define BULLET_H

#include "boardobject.h"
#include "tank.h"

class Tank;

class Bullet : public BoardObject
{
    Q_OBJECT

public:
    explicit Bullet(Tank* attacker, QObject* parent = nullptr);
    virtual ~Bullet();

    Tank* getAttacker() const;

    void setAttacker(Tank* attacker);

    virtual void move();
    void attack(Tank& enemy);

private:
    Tank* attacker;
};

#endif // BULLET_H
