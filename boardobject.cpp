#include "boardobject.h"
#include <cstdlib>

BoardObject::BoardObject(QObject *parent) : QObject(parent) {
    qDebug() << "Constructor: BoardObject";
}

BoardObject::~BoardObject() {
    qDebug() << "Destructor: BoardObject";
}

Rotate BoardObject::getDirection() const {
    return direction;
}

void BoardObject::setDirection(Rotate value) {
    direction = value;
}

void BoardObject::setRandomDirection() {
    direction = Rotate(rand() % 4);
    qDebug() << direction;
}

void BoardObject::move(Rotate value) {

}
