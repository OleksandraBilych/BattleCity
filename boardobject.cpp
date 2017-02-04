#include "boardobject.h"
#include <cstdlib>

BoardObject::BoardObject(QObject *parent) :
    QObject(parent),
    parent(parent) {

    qDebug() << "Constructor: BoardObject";
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

void BoardObject::setRandomDirection() {
    direction = Direction(rand() % 4);
}

