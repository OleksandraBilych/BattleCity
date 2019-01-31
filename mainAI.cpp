#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mainAI.h"

MainAI::MainAI(QObject *parent) : QObject(parent)
{
    qDebug() << "Constructor main artificial intelligence";

    board.reset(new Board(parent));
    animation = false;

    tankThread.reset(new QThread(this));
    bulletThread.reset(new QThread(this));

    tankTimer.reset(new QTimer());
    bulletTimer.reset(new QTimer());
    tankTimer->setInterval(90);
    bulletTimer->setInterval(50);

    tankTimer->moveToThread(tankThread.data());
    bulletTimer->moveToThread(bulletThread.data());

    tankAI.reset(new TankAI);
    bulletAI.reset(new BulletAI);

    connect(tankTimer.data(), SIGNAL(timeout()), this, SLOT(tankEvents()));
    connect(bulletTimer.data(), SIGNAL(timeout()), this, SLOT(bulletEvents()));

    tankTimer->connect(tankThread.data(), SIGNAL(started()), SLOT(start()));
    tankTimer->connect(tankThread.data(), SIGNAL(finished()), SLOT(stop()));
    bulletTimer->connect(bulletThread.data(), SIGNAL(started()), SLOT(start()));
    bulletTimer->connect(bulletThread.data(), SIGNAL(finished()), SLOT(stop()));

    connect(board.data(), SIGNAL(playerIsAlive(bool)), this, SLOT(setAnimation(bool)));
    connect(board.data(), SIGNAL(playerIsAlive(bool)), this, SLOT(gameOverAnimation()));
    connect(board.data(), SIGNAL(playerIsAlive(bool)), this, SLOT(openResultScreen()));

    connect(board.data(), SIGNAL(playerWin()), this, SLOT(openResultScreen()));
}

MainAI::~MainAI()
{

}

void MainAI::tankEvents()
{
    if (!(rand() % 10)) {
        tankAI->sendAtackSignal(board.data());
    } else {
        tankAI->sendPressSignal(board.data());
    }
}

void MainAI::bulletEvents()
{
    bulletAI->sendMoveSignal(board.data());
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
    if (!tankTimer->isActive() && !bulletTimer->isActive()) {
        tankThread->start();
        bulletThread->start();
    }
}

void MainAI::stopTimer()
{
    if (tankTimer->isActive() && bulletTimer->isActive()) {
        tankThread->quit();
        bulletThread->quit();
    }
}

void MainAI::gameOverAnimation()
{
    QObject* object = getRootObject();
    if (object == nullptr)
        return;

    QObject* animation = object->findChild<QObject *>("gameOver");
    if (animation) {
        animation->setProperty("focus", true);
        animation->setProperty("visible", true);
    }

    QTime dieTime= QTime::currentTime().addSecs(5);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainAI::openResultScreen()
{
    qDebug() << "Open result dialog!";
    QObject* object = getRootObject();
    if (object == nullptr)
        return;

    QObject* resultScreen = object->findChild<QObject *>("resultScreen");
    if (resultScreen) {
        resultScreen->setProperty("visible", true);
    }
}

QObject* MainAI::getRootObject()
{
    QQmlContext *currentContext = QQmlEngine::contextForObject(board.data());
    if (currentContext == nullptr)
        return nullptr;

    QQmlEngine *engine = currentContext->engine();
    QObject* object = qobject_cast<QQmlApplicationEngine*>(engine)->rootObjects().at(0);

    return object;
}
