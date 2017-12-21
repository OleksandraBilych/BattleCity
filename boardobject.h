#ifndef BOARDOBJECT_H
#define BOARDOBJECT_H

#include <QtQuick/QQuickPaintedItem>
#include <QObject>
#include <QDebug>
#include "enums.h"

class BoardObject : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int direction READ getDirection WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(int coordinate_x READ getX WRITE setX NOTIFY XChanged)
    Q_PROPERTY(int coordinate_y READ getY WRITE setY NOTIFY YChanged)

public:
    explicit BoardObject(QQuickItem *parent = 0);
    virtual ~BoardObject();

    int getDirection() const;
    int getX() const;
    int getY() const;

    void setDirection(int value);
    void setX(int value);
    void setY(int value);

    void updateDirection(int value);
    void updateDirection();

    virtual void move() = 0;
    void paint(QPainter *painter);

signals:
    void directionChanged(int value);
    void XChanged(int value);
    void YChanged(int value);

protected:
    int direction;
    int coordinate_x;
    int coordinate_y;
};

#endif // BOARDOBJECT_H
