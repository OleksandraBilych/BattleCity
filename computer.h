#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <board.h>

class Computer : public QObject {
    Q_OBJECT

private:
   QTimer *myTimer;
   Board* board;
   bool animation;

public:
   explicit Computer(QObject *parent = 0);
   ~Computer();

   Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation NOTIFY stopStartAnimation)

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
};

#endif // COMPUTER_H

