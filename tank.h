#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QDebug>
#include "enums.h"

class Tank : public QObject {
protected:
    float hitPoints;
    float hitPointsLimit;
    float damage;
    bool isDead;

    Q_OBJECT
public:
    explicit Tank(QObject *parent = 0);
    virtual ~Tank();

signals:

public slots:

    float getDamage() const;
    float getHitPoints() const;
    float getHitPointsLimit() const;
    bool getIsDead() const;

    void setHitPoints(float value);
    void setHitPointsLimit(float value);
    void setDamage(float value);
    void setIsDead();

    void rotate(Rotate value);
    void attack(float value);
    void takeDamage(float value);
};

#endif // TANK_H
