#include "objectscleaner.h"
#include <QTime>

ObjectsCleaner::ObjectsCleaner(QObject *parent, Board *board) : QObject(parent)
{
    timer.reset(new QTimer(this));
    setBoard(board);

    connect(timer.data(), SIGNAL(timeout()), this, SLOT(deleteObjects()));
}

ObjectsCleaner::~ObjectsCleaner()
{

}

ObjectsCleaner* ObjectsCleaner::instance = 0;

ObjectsCleaner* ObjectsCleaner::getInstance(QObject *parent, Board *board)
{
    if (instance == 0)
        instance = new ObjectsCleaner(parent, board);

    return instance;
}

void ObjectsCleaner::setBoard(Board* board)
{
    if (board != nullptr)
        this->board = board;
}

bool ObjectsCleaner::isDeadObjectOnBoard()
{
    bool isDeadObjectExisted = false;

    // check if a dead tank presents on the board
    QList<Enemy*> enemies(board->getEnemies());
    for (Enemy* enemy : enemies) {
        if (enemy->getIsDead()) {
            isDeadObjectExisted = true;
            return isDeadObjectExisted;
        }
    }

    // check if a dead bullet presents on the board
    QList<Bullet*> bullets(board->getBullets());
    for (Bullet* bullet : bullets) {
        if (bullet->getIsDead()) {
            isDeadObjectExisted = true;
            return isDeadObjectExisted;
        }
    }

    if (board->getPlayer()->getIsDead()) {
        isDeadObjectExisted = true;
        return isDeadObjectExisted;
    }

    return isDeadObjectExisted;
}

QVector<BoardObject*> ObjectsCleaner::deadObjects()
{
    QVector<BoardObject*> deadObjects;

    QList<Enemy*> enemies(board->getEnemies());
    for (Enemy* enemy : enemies) {
        if (enemy->getIsDead())
            deadObjects.append(enemy);
    }

    QList<Bullet*> bullets(board->getBullets());
    for (Bullet* bullet : bullets) {
        if (bullet->getIsDead())
            deadObjects.append(bullet);
    }

    if (board->getPlayer()->getIsDead())
        deadObjects.append(board->getPlayer());

    return deadObjects;
}

void ObjectsCleaner::deleteObjects()
{
    QVector<BoardObject*> objects = deadObjects();

    for (BoardObject* object : objects) {
        if (object->getTimeOfDeath().msecsTo(QTime::currentTime()) > 80)
            board->removeObject(object);
    }

    if (!isDeadObjectOnBoard())
        stopTimer();

    return;
}

void ObjectsCleaner::startTimer()
{
    if (!timer->isActive()) {
        qDebug() << "Start timer";
        timer->start(10);
    }
}

void ObjectsCleaner::stopTimer()
{
    if (timer->isActive()) {
        qDebug() << "Stop timer";
        timer->stop();
    }
}

void ObjectsCleaner::launchCleaner(bool signOfLife)
{
    if (signOfLife)
        startTimer();
}
