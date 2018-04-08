#include "bulletAI.h"
#include <QTime>

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
        QPair<Objects, BoardObject*> collisionObject = board->move(bullet);
        Objects objectType = collisionObject.first;

        if (objectType == Objects::emptyCell)
            bullet->move();
        else if (objectType == Objects::windowBorders) {
            board->removeBullet(bullet);
        }
        else if (objectType == Objects::enemy) {
            Tank* tank = dynamic_cast<Tank*>(collisionObject.second);

            bullet->setImageURL("qrc:/images/explodedBullet.png");
            bullet->attack(*tank);

            if (tank->getIsDead()) {
                if (tank->getIsPlayer()) {
                    // TO DO: game over
                } else {
                    board->removeEnemy(dynamic_cast<Enemy*>(tank));
                }
            }

            board->removeBullet(bullet);
        }
        // else if (collisionObject == Objects::player)
    }
}

