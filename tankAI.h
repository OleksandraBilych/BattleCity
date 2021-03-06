# pragma once

#include <QObject>
#include <QDebug>
#include "board.h"

class TankAI : public QObject
{
    Q_OBJECT

public:
    explicit TankAI(QObject *parent = nullptr);
    ~TankAI();

    void sendPressSignal(Board* board);
    Q_INVOKABLE void sendPressSignal(Board* board, Tank* tank, Qt::Key keyDirection = Qt::Key_unknown);

    void sendAtackSignal(Board* board);
};
