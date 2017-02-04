#ifndef BOARDOBJECT_H
#define BOARDOBJECT_H

#include <QObject>
#include <QDebug>
#include "enums.h"

class BoardObject : public QObject {
protected:
    Direction direction;
    QObject *parent;

    Q_OBJECT
public:
    explicit BoardObject(QObject *parent = 0);
    virtual ~BoardObject();

    Direction getDirection() const;
    void setDirection(Direction value);

    void setRandomDirection();
    void move(Direction value);

    virtual void rotate(Direction value) = 0;
};

#endif // BOARDOBJECT_H
