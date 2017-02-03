#ifndef BOARDOBJECT_H
#define BOARDOBJECT_H

#include <QObject>
#include <QDebug>
#include "enums.h"

class BoardObject : public QObject {
protected:
    Rotate direction;

    Q_OBJECT
public:
    explicit BoardObject(QObject *parent = 0);
    virtual ~BoardObject();

    Rotate getDirection() const;
    void setDirection(Rotate value);

    void setRandomDirection();
    void move(Rotate value);

    virtual void rotate(Rotate value) = 0;
    virtual void attack(float value) = 0;
};

#endif // BOARDOBJECT_H
