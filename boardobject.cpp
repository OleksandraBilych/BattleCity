#include "boardobject.h"
#include <cstdlib>

BoardObject::BoardObject(QQuickItem *parent) : QQuickPaintedItem(parent) {
    qDebug() << "Constructor: BoardObject";
}

BoardObject::~BoardObject() {
    qDebug() << "Destructor: BoardObject";
}

int BoardObject::getDirection() const {
    qDebug() << "getDirection" << direction;
    return direction;
}

int BoardObject::getX() const {
    qDebug() << "getX" << coordinate_x;
    return coordinate_x;
}

int BoardObject::getY() const {
    qDebug() << "getY" << coordinate_y;
    return coordinate_y;
}

void BoardObject::setDirection(int value) {
    qDebug() << "setDirection" << value;

    if (value != direction) {
            direction = value;
            update();   // repaint with the new color
            emit directionChanged(direction);
    }
}

void BoardObject::setX(int value) {
    qDebug() << "setX" << value;

    if (value != coordinate_x) {
            coordinate_x = value;
            update();   // repaint with the new color
            emit XChanged(coordinate_x);
    }
}

void BoardObject::setY(int value) {
    qDebug() << "setY" << value;

    if (value != coordinate_y) {
            coordinate_y = value;
            update();   // repaint with the new color
            emit YChanged(coordinate_y);
    }
}

void BoardObject::updateDirection(int value) {
    qDebug() << "updateDirection";
    direction = value;
    emit directionChanged(value);
    update();
}

void BoardObject::updateDirection() {
    qDebug() << "updateDirection";
    direction = (rand() % 4) * 90;
    emit directionChanged(direction);
}

void BoardObject::paint(QPainter *painter)
{
//    QPen pen(m_color, 2);
//    painter->setPen(pen);
//    painter->setRenderHints(QPainter::Antialiasing, true);
//    painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);
}
