#include "tank.h"

Tank::Tank(QObject *parent) : QObject(parent) {
    qDebug() << "Constructor: Tank";
}

Tank::~Tank() {
    qDebug() << "Destructor: Tank";
}
