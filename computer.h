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
public:
   explicit Computer(QObject *parent = 0);
   ~Computer();

   Board* getBoard() const;
   void setBoard(Board* other);

signals:

public slots:
   void sendPressSignal();
};

#endif // COMPUTER_H

