# pragma once

#include <QObject>
#include "board.h"

class BulletAI : public QObject
{
    Q_OBJECT

public:
    explicit BulletAI(QObject *parent = nullptr);
    ~BulletAI();

   void sendMoveSignal(Board* board);
};
