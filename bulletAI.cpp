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
        Objects collisionObject = board->move(bullet);

        if (collisionObject == Objects::emptyCell)
            bullet->move();
        else if (collisionObject == Objects::windowBorders)
            board->removeBullet(bullet);
        // else if (collisionObject == Objects::enemy)
        // else if (collisionObject == Objects::player)
    }
}
