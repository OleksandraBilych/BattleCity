#include "playersbase.h"

PlayersBase::PlayersBase(int coordinate_x, int coordinate_y, QQuickItem *parent) : BoardObject(parent)
{
    qDebug() << "Constructor: PlayersBase";

    objectWidth = 50;
    objectHeight = 50;
    hitPoints = 50;

    this->direction = 0;
    this->coordinate_x = coordinate_x;
    this->coordinate_y = coordinate_y;

    imageURL = "qrc:/images/base.png";
}

PlayersBase::~PlayersBase()
{

}

float PlayersBase::getHitPoints() const
{
    return hitPoints;
}

void PlayersBase::setHitPoints(float value)
{
    hitPoints = value;
}
