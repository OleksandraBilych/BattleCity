#include "computer.h"

Computer::Computer(QObject *parent) : QObject(parent) {
    qDebug() << "Constructor Computer";

    board = new Board(parent);
    myTimer = new QTimer(this);
    myTimer->start(5000);
    connect(myTimer, SIGNAL (timeout()), this, SLOT (sendPressSignal()));
}

Computer::~Computer() {
    if ( board != nullptr ) {
        delete board;
    }
}

void Computer::sendPressSignal() {
    qDebug() << "sendPressSignal";

    (board->getEnemy())->setDirection(90);
}

Board* Computer::getBoard() const {
    return board;
}

void Computer::setBoard(Board* other) {
    if ( board != nullptr ) {
        delete board;
    }

    board = other;
}
