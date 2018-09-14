#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include "cell.h"
#include "enemy.h"
#include "player.h"
#include "bullet.h"
#include "wall.h"
#include "playersbase.h"

class Board : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Enemy> enemies READ enemies NOTIFY enemiesChanged)
    Q_PROPERTY(Player player READ getPlayer NOTIFY playerChanged)
    Q_PROPERTY(QQmlListProperty<Bullet> bullets READ bullets NOTIFY bulletsChanged)
    Q_PROPERTY(QQmlListProperty<Wall> walls READ walls NOTIFY wallsChanged)
    Q_PROPERTY(PlayersBase base READ getBase NOTIFY baseChanged)

public:
    explicit Board(QObject *parent = 0);
    ~Board();

    QPair<Objects, BoardObject*> move(Tank* tank);
    QPair<Objects, BoardObject*> move(Bullet* bullet);
    Q_INVOKABLE void addBullet(Bullet* bullet);
    void removeObject(BoardObject* object);

    QVector<QVector<Cell*>> calcPrevAndNextCells(BoardObject* object);
    QPair<Objects, BoardObject*> IdentifyObjectType(QVector<Cell*> objectCells);

    QQmlListProperty<Enemy> enemies();
    QList<Enemy*> getEnemies();

    Player* getPlayer() const;

    QQmlListProperty<Bullet> bullets();
    QList<Bullet*> getBullets();

    QQmlListProperty<Wall> walls();
    QList<Wall*> getWalls();

    PlayersBase* getBase() const;

signals:
    void enemiesChanged(QQmlListProperty<Enemy>);
    void playerChanged(Player* player);
    void bulletsChanged(QQmlListProperty<Bullet>);
    void playerIsAlive(bool value);
    void wallsChanged(QQmlListProperty<Wall>);
    void baseChanged(PlayersBase* base);

private:
    bool areCellsFree(QVector<Cell*> cells);
    void freeCells(QVector<Cell*> cells);

    QList<Enemy*> m_enemies;
    QScopedPointer<Player> player;
    QVector<QVector<Cell*>> cells;
    QList<Bullet*> m_bullets;
    QList<Wall*> m_walls;
    QScopedPointer<PlayersBase> base;
};

#endif // BOARD_H
