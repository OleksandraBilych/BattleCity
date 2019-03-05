#ifndef PLAYERSBASE_H
#define PLAYERSBASE_H

#include "boardobject.h"

class PlayersBase : public BoardObject
{
     Q_OBJECT

public:
    explicit PlayersBase(int coordinate_x, int coordinate_y, QObject *parent = nullptr);
    PlayersBase() {}
    virtual ~PlayersBase();

    float getHitPoints() const;

    void setHitPoints(float value);

    virtual void move() {}

private:
    float hitPoints;
};

#endif // PLAYERSBASE_H
