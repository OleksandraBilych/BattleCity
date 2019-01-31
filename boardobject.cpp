#include <cstdlib>
#include <QColor>
#include <QPainter>
#include <typeinfo>
#include <QGuiApplication>

#include "boardobject.h"
#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "wall.h"
#include "playersbase.h"
#include "objectscleaner.h"

BoardObject::BoardObject(QObject *parent) : QObject(parent)
{
    isDead = false;
    QObject::connect(this, SIGNAL(signOfLifeChanged(bool)),
                         ObjectsCleaner::getInstance(), SLOT(launchCleaner(bool)));
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

QTime BoardObject::getTimeOfDeath() const
{
    return timeOfDeath;
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
        if (isDead) {
            timeOfDeath = QTime::currentTime();
            emit signOfLifeChanged(isDead);
        }
    }
}

void BoardObject::updateDirection(int value)
{
    direction = value;
    emit directionChanged(value);
}

void BoardObject::updateDirection()
{
    direction = (rand() % 4) * 90;
    emit directionChanged(direction);
}

Objects BoardObject::getTypeObject()
{
    if (typeid(*this) == typeid(Bullet))
        return Objects::bullet;
    else if (typeid(*this) == typeid(Enemy))
        return Objects::enemy;
    else if (typeid(*this) == typeid(Player))
        return Objects::player;
    else if (typeid(*this) == typeid(Wall))
        return Objects::wall;
    else if (typeid(*this) == typeid(PlayersBase))
        return Objects::playersBase;

    return Objects::undefined;
}
