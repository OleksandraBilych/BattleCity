#include "computer.h"

Computer::Computer(QObject *parent) : QObject(parent) {
   myTimer = new QTimer(this);
   myTimer->start(100);
   connect(myTimer, SIGNAL (timeout()), this, SLOT (testSlot()));
}
