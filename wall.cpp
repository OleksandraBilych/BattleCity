#include "wall.h"
#include "constants.h"

Wall::Wall(int direction, int coordinate_x, int coordinate_y, QObject *parent) : BoardObject(parent)
{
    qDebug() << "Constructor: Wall";

    objectWidth = wallWidth;
    objectHeight = wallHeight;
    hitPoints = wallHitPoints;

    this->direction = direction;
    this->coordinate_x = coordinate_x;
    this->coordinate_y = coordinate_y;

    imageURL = "qrc:/images/wall50x25.png";
}

Wall::~Wall()
{

}

float Wall::getHitPoints() const
{
    return hitPoints;
}

void Wall::setHitPoints(float value)
{
    hitPoints = value;
}
