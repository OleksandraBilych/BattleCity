#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QDebug>

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

};

#endif // TANK_H
