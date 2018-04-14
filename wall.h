#ifndef WALL_H
#define WALL_H

#include "boardobject.h"

class Wall : BoardObject
{
public:
    explicit Wall(int direction, int coordinate_x, int coordinate_y, QQuickItem *parent = 0);
    virtual ~Wall();

    float getHitPoints() const;

    void setHitPoints(float value);

    void takeDamage(float value);

private:
    float hitPoints;
};

#endif // WALL_H
