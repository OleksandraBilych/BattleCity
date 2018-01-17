#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include "cell.h"
#include "enemy.h"
#include "player.h"
#include "bullet.h"

class Board : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Enemy> enemies READ enemies NOTIFY enemiesChanged)
    Q_PROPERTY(Player player READ getPlayer NOTIFY playerChanged)
    Q_PROPERTY(QQmlListProperty<Bullet> bullets READ bullets NOTIFY bulletsChanged)

public:
    explicit Board(QObject *parent = 0);
    ~Board();

    Q_INVOKABLE void move(Tank* tank, Qt::Key keyDirection = Qt::Key_unknown);
    Q_INVOKABLE void attack(Tank* tank);

    QQmlListProperty<Enemy> enemies();
    QList<Enemy*> getEnemies();

    Player* getPlayer() const;

    QQmlListProperty<Bullet> bullets();

signals:
    void enemiesChanged(QQmlListProperty<Enemy>);
    void playerChanged(Player* player);
    void bulletsChanged(QQmlListProperty<Bullet>);

private:
    bool AreCellsFree(QVector<Cell*> cells);
    void FreeCells(QVector<Cell*> cells);

    QList<Enemy*> m_enemies;
    QScopedPointer<Player> player;
    QVector<QVector<Cell*>> cells;
    QList<Bullet*> m_bullets;
};

#endif // BOARD_H
