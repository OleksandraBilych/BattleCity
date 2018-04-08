#include "boardobject.h"
#include <cstdlib>
#include <QColor>
#include <QPainter>

BoardObject::BoardObject(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    isDead = false;
}

BoardObject::~BoardObject()
{

}

int BoardObject::getDirection() const
{
    //qDebug() << "getDirection" << direction;
    return direction;
}

int BoardObject::getX() const
{
    //qDebug() << "getX" << coordinate_x;
    return coordinate_x;
}

int BoardObject::getY() const
{
    //qDebug() << "getY" << coordinate_y;
    return coordinate_y;
}

int BoardObject::getWidth() const
{
    return objectWidth;
}

int BoardObject::getHeight() const
{
    return objectHeight;
}

QVariant BoardObject::getImageURL() const
{
    return imageURL;
}

bool BoardObject::getIsDead() const
{
    return isDead;
}

void BoardObject::setDirection(int value)
{
    //qDebug() << "setDirection" << value;

    if (value != direction) {
        direction = value;
        emit directionChanged(direction);
    }
}

void BoardObject::setX(int value)
{
    //qDebug() << "setX" << value;

    if (value != coordinate_x) {
        coordinate_x = value;
        emit XChanged(coordinate_x);
    }
}

void BoardObject::setY(int value)
{
    //qDebug() << "setY" << value;

    if (value != coordinate_y) {
        coordinate_y = value;
        emit YChanged(coordinate_y);
    }
}

void BoardObject::setWidth(int value)
{
    if (value != objectWidth) {
        objectWidth = value;
        emit WidthChanged(objectWidth);
    }
}

void BoardObject::setHeight(int value)
{
    if (value != objectHeight) {
        objectHeight = value;
        emit HeightChanged(objectHeight);
    }
}

void BoardObject::setImageURL(QVariant value)
{
    if (value != imageURL) {
        imageURL = value;
        emit imageURLChanged(imageURL);
    }
}

void BoardObject::setIsDead(bool value)
{
    if (value != isDead) {
        isDead = value;
    }
}

void BoardObject::updateDirection(int value)
{
    qDebug() << "updateDirection";
    direction = value;
    emit directionChanged(value);
}

void BoardObject::updateDirection()
{
    qDebug() << "updateDirection";
    direction = (rand() % 4) * 90;
    emit directionChanged(direction);
}

void BoardObject::paint(QPainter *painter)
{
}
