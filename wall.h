#ifndef WALL_H
#define WALL_H

#include "boardobject.h"

class Wall : public BoardObject
{ 
    Q_OBJECT

public:
    explicit Wall(int direction, int coordinate_x, int coordinate_y, QObject *parent = 0);
    Wall() {}
    virtual ~Wall();

    float getHitPoints() const;

    void setHitPoints(float value);

    virtual void move() {}

private:
    float hitPoints;
};

#endif // WALL_H
