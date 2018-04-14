#include "wall.h"

Wall::Wall(int direction, int coordinate_x, int coordinate_y, QQuickItem *parent) : BoardObject(parent)
{
    qDebug() << "Constructor: Wall";

    objectWidth = 50;
    objectHeight = 25;
    hitPoints = 50;

    this->direction = direction;
    this->coordinate_x = coordinate_x;
    this->coordinate_y = coordinate_y;

    imageURL = "qrc:/images/wall50x25.png";
}

Wall::~Wall()
{

}

float Tank::getHitPoints() const
{
    return hitPoints;
}

void Tank::setHitPoints(float value)
{
    hitPoints = value;
}

void Tank::takeDamage(float value)
{

}
