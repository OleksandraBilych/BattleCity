#include "mainAI.h"

MainAI::MainAI(QObject *parent) : QObject(parent)
{
    qDebug() << "Constructor main artificial intelligence";

    board.reset(new Board(parent));
    animation = false;
    myTimer.reset(new QTimer(this));
    enemyAI.reset(new EnemyAI);
    bulletAI.reset(new BulletAI);

    connect(myTimer.data(), SIGNAL (timeout()), this, SLOT (events()));
}

MainAI::~MainAI()
{

}

void MainAI::events()
{
    enemyAI->sendPressSignal(board.data());
    bulletAI->sendMoveSignal(board.data());
}

Board* MainAI::getBoard() const
{
    return board.data();
}

bool MainAI::getAnimation() const
{
    return animation;
}

void MainAI::setAnimation(bool value)
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

void MainAI::startTimer()
{
    if (!myTimer->isActive()) {
        myTimer->start(100);
    }
}

void MainAI::stopTimer()
{
    if (myTimer->isActive())
        myTimer->stop();
}
