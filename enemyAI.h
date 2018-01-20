#ifndef ENEMYAI_H
#define ENEMYAI_H

#include <QObject>
#include <QDebug>
#include "board.h"

class EnemyAI : public QObject
{
    Q_OBJECT

public:
   explicit EnemyAI(QObject *parent = 0);
   ~EnemyAI();

   void sendPressSignal(Board* board);
};

#endif // COMPUTER_H

