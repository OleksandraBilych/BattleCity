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
    //TO DO: rewrite if
    for (auto& bullet : board->getBullets()) {
        QPair<Objects, BoardObject*> collisionObject = board->move(bullet);
        Objects objectType = collisionObject.first;

        if (objectType == Objects::emptyCell)
            bullet->move();
        else if (objectType == Objects::windowBorders) {
            bullet->setImageURL("qrc:/images/explodedBullet.png");
            bullet->setIsDead(true);
        } else if (objectType == Objects::enemy || objectType == Objects::player) {
            Tank* tank = dynamic_cast<Tank*>(collisionObject.second);

            bullet->setImageURL("qrc:/images/explodedBullet.png");
            bullet->attack(*tank);

            if (tank->getIsDead())
                qDebug() << "GAME OVER!";

            bullet->setIsDead(true);
        } else if (objectType == Objects::bullet) {
            bullet->setImageURL("qrc:/images/explodedBullet.png");
            bullet->setIsDead(true);

            Bullet* anotherBullet = dynamic_cast<Bullet*>(collisionObject.second);
            anotherBullet->setImageURL("qrc:/images/explodedBullet.png");
            anotherBullet->setIsDead(true);
        }
    }
}

