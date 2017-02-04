#include "boardobject.h"
#include <cstdlib>

BoardObject::BoardObject(QObject *parent) : QObject(parent) {
    qDebug() << "Constructor: BoardObject";
    direction = Direction::dir_right;
}

BoardObject::~BoardObject() {
    qDebug() << "Destructor: BoardObject";
}

Direction BoardObject::getDirection() const {
    return direction;
}

void BoardObject::setDirection(Direction value) {
    direction = value;
}

void BoardObject::updateDirection(Direction value) {
    direction = value;
    emit directionChanged(value);
}

void BoardObject::updateDirection() {
    direction = Direction(rand() % 4);
    emit directionChanged(direction);
}
