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

   Board* getBoard() const; // use this method only for setContextProperty
   bool getAnimation() const;

   void setAnimation(bool value);

   void startTimer();
   void stopTimer();

signals:
   void stopStartAnimation(bool value);

public slots:
   void sendPressSignal();

private:
   QScopedPointer<QTimer> myTimer;
   QScopedPointer<Board> board;
   bool animation;
};

#endif // COMPUTER_H

