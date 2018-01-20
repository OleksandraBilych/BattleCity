#include "bulletAI.h"

BulletAI::BulletAI(QObject *parent) : QObject(parent)
{
    qDebug() << "Constructor bullet's artificial intelligence";
}

BulletAI::~BulletAI()
{

}

void BulletAI::sendMoveSignal(Board* board)
{
    for (auto& bullet : board->getBullets()) {
        board->move(bullet);
    }
}
