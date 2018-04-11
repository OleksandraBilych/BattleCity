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
        if (bullet->getIsDead())
            continue;

        QPair<Objects, BoardObject*> collisionObject = board->move(bullet);
        Objects objectType = collisionObject.first;

        if (objectType == Objects::emptyCell)
            bullet->move();
        else {
            bullet->setImageURL("qrc:/images/explodedBullet.png");
            bullet->setIsDead(true);

            if (objectType == Objects::enemy || objectType == Objects::player) {
                Tank* tank = dynamic_cast<Tank*>(collisionObject.second);

                bullet->attack(*tank);

                if (objectType == Objects::enemy && tank->getIsDead()) {
                    Player* player = dynamic_cast<Player*>(bullet->getAttacker());
                    player->incrementNumberOfDeadTanks();

                    qDebug() << "NumberOfDeadTanks: " << player->getNumberOfDeadTanks();
                }
            } else if (objectType == Objects::bullet) {
                Bullet* anotherBullet = dynamic_cast<Bullet*>(collisionObject.second);

                anotherBullet->setImageURL("qrc:/images/explodedBullet.png");
                anotherBullet->setIsDead(true);
            }
        }
    }
}

