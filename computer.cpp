#include "computer.h"

Computer::Computer(QObject *parent) : QObject(parent)
{
    qDebug() << "Constructor Computer";

    board = new Board(parent);
    animation = false;
    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL (timeout()), this, SLOT (sendPressSignal()));
}

Computer::~Computer()
{
    if ( board != nullptr )
        delete board;
}

void Computer::sendPressSignal()
{
    qDebug() << "sendPressSignal";

    for (auto enemy : board->getEnemies()) {
        if (!(rand() % 20)) {
            enemy->updateDirection();
        }

        board->move(enemy);
    }
}

Board* Computer::getBoard() const
{
    return board;
}

bool Computer::getAnimation() const
{
    return animation;
}

void Computer::setBoard(Board* other)
{
    if (board != nullptr)
        delete board;

    board = other;
}

void Computer::setAnimation(bool value)
{
    if (animation != value) {
        animation = value;

        if (animation)
            startTimer();
        else
            stopTimer();

        emit stopStartAnimation(animation);
    }
}

void Computer::startTimer()
{
    if (!myTimer->isActive()) {
        myTimer->start(100);
    }
}

void Computer::stopTimer()
{
    if (myTimer->isActive())
        myTimer->stop();
}
