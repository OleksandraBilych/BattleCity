#ifndef BULLET_H
#define BULLET_H

#include "boardobject.h"
#include "tank.h"

class Tank;

class Bullet : public BoardObject {
private:
    const Tank* attacker;
    const Tank* enemy;
public:
    Bullet(const Tank& attacker, QObject* parent = 0);
    virtual ~Bullet();

    const Tank* getAttacker() const;
    const Tank* getEnemy() const;

    void setAttacker(const Tank& attacker);
    void setEnemy(const Tank& enemy);

    virtual void rotate(Direction value);
    void attack();
};

#endif // BULLET_H
