#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <board.h>

class Computer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation NOTIFY stopStartAnimation)

public:
   explicit Computer(QObject *parent = 0);
   ~Computer();   

   Board* getBoard() const;
   bool getAnimation() const;

   void setBoard(Board* other);
   void setAnimation(bool value);

   void startTimer();
   void stopTimer();

signals:
   void stopStartAnimation(bool value);

public slots:
   void sendPressSignal();

private:
   QTimer *myTimer;
   Board* board;
   bool animation;
};

#endif // COMPUTER_H

