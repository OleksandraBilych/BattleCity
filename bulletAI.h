#ifndef BULLETAI_H
#define BULLETAI_H

#include <QObject>
#include "board.h"

class BulletAI : public QObject
{
    Q_OBJECT

public:
    explicit BulletAI(QObject *parent = 0);
    ~BulletAI();

   void sendMoveSignal(Board* board);
};

#endif // BULLETAI_H
