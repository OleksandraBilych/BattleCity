#ifndef BOARDOBJECT_H
#define BOARDOBJECT_H

#include <QtQuick/QQuickPaintedItem>
#include <QObject>
#include <QDebug>
#include <QTime>
#include "enums.h"

class BoardObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int direction READ getDirection WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(int coordinate_x READ getX WRITE setX NOTIFY XChanged)
    Q_PROPERTY(int coordinate_y READ getY WRITE setY NOTIFY YChanged)
    Q_PROPERTY(int objectWidth READ getWidth WRITE setWidth NOTIFY WidthChanged)
    Q_PROPERTY(int objectHeight READ getHeight WRITE setHeight NOTIFY HeightChanged)
    Q_PROPERTY(QVariant imageURL READ getImageURL WRITE setImageURL NOTIFY imageURLChanged)
    Q_PROPERTY(bool isDead READ getIsDead WRITE setIsDead NOTIFY signOfLifeChanged)

public:
    explicit BoardObject(QObject *parent = nullptr);
    virtual ~BoardObject();

    int getDirection() const;
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    QVariant getImageURL() const;
    bool getIsDead() const;
    QTime getTimeOfDeath() const;

    void setDirection(int value);
    void setX(int value);
    void setY(int value);
    void setWidth(int value);
    void setHeight(int value);
    void setImageURL(QVariant value);
    void setIsDead(bool value);

    void updateDirection(int value);
    void updateDirection();

    virtual void move() = 0;

    Objects getTypeObject();

signals:
    void directionChanged(int value);
    void XChanged(int value);
    void YChanged(int value);
    void WidthChanged(int value);
    void HeightChanged(int value);
    void imageURLChanged(QVariant value);
    void signOfLifeChanged(bool value);

protected:
    int direction;
    int coordinate_x;
    int coordinate_y;
    int objectWidth;
    int objectHeight;
    QVariant imageURL;
    bool isDead;
    QTime timeOfDeath;
};

#endif // BOARDOBJECT_H
