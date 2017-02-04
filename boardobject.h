#ifndef BOARDOBJECT_H
#define BOARDOBJECT_H

#include <QObject>
#include <QDebug>
#include "enums.h"

class BoardObject : public QObject {
    Q_OBJECT
protected:
    Direction direction;

public:
    explicit BoardObject(QObject *parent = 0);
    virtual ~BoardObject();

    Q_PROPERTY(Direction direction READ getDirection WRITE setDirection NOTIFY directionChanged)
    Direction getDirection() const;
    void setDirection(Direction value);

    void updateDirection(Direction value);
    void updateDirection();

    virtual void move(Direction value) = 0;

signals:
    void directionChanged(Direction value);
};

#endif // BOARDOBJECT_H
