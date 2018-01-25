#include "mainAI.h"

MainAI::MainAI(QObject *parent) : QObject(parent)
{
    qDebug() << "Constructor main artificial intelligence";

    board.reset(new Board(parent));
    animation = false;

    motionTimer.reset(new QTimer(this));
    atackTimer.reset(new QTimer(this));

    tankAI.reset(new TankAI);
    bulletAI.reset(new BulletAI);

    connect(motionTimer.data(), SIGNAL (timeout()), this, SLOT (motionEvents()));
    connect(atackTimer.data(), SIGNAL (timeout()), this, SLOT (atackEvents()));
}

MainAI::~MainAI()
{

}

void MainAI::motionEvents()
{
    tankAI->sendPressSignal(board.data());
    bulletAI->sendMoveSignal(board.data());
}

void MainAI::atackEvents()
{
    tankAI->sendAtackSignal(board.data());
}

void atackEvents();

Board* MainAI::getBoard() const
{
    return board.data();
}

bool MainAI::getAnimation() const
{
    return animation;
}

TankAI* MainAI::getTankAI() const
{
    return tankAI.data();
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
    if (!motionTimer->isActive() && !atackTimer->isActive()) {
        motionTimer->start(100);
        atackTimer->start(1000);
    }
}

void MainAI::stopTimer()
{
    if (motionTimer->isActive() && atackTimer->isActive()) {
        motionTimer->stop();
        atackTimer->stop();
    }
}
