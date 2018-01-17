#ifndef BULLET_H
#define BULLET_H

#include "boardobject.h"
#include "tank.h"

class Tank;

class Bullet : public BoardObject
{
    Q_OBJECT

public:
    explicit Bullet(const Tank* attacker, QObject* parent = 0);
    Bullet();
    virtual ~Bullet();

    const Tank* getAttacker() const;

    void setAttacker(const Tank* attacker);

    virtual void move();
    void attack(Tank& enemy);

private:
    const Tank* attacker; // change to const Tank*
};

#endif // BULLET_H
