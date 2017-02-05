#ifndef BULLET_H
#define BULLET_H

#include "boardobject.h"
#include "tank.h"

class Tank;

class Bullet : public BoardObject {
    Q_OBJECT
private:
    Tank* attacker;
public:
    Bullet(Tank* attacker, QObject* parent = 0);
    virtual ~Bullet();

    Tank* getAttacker() const;

    void setAttacker(Tank* attacker);

    virtual void move();
    void attack(Tank& enemy);
};

#endif // BULLET_H
