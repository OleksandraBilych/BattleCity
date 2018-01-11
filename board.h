#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include "cell.h"
#include "enemy.h"
#include "player.h"

class Board : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Enemy> enemies READ enemies NOTIFY enemiesChanged)
    Q_PROPERTY(Player player READ getPlayer NOTIFY playerChanged)

public:
    explicit Board(QObject *parent = 0);
    ~Board();

    Q_INVOKABLE void move(Tank* tank, Qt::Key keyDirection = Qt::Key_unknown);

    QQmlListProperty<Enemy> enemies();
    QList<Enemy*> getEnemies();

    Player* getPlayer() const;

signals:
    void enemiesChanged(QQmlListProperty<Enemy>);
    void playerChanged(Player* player);

private:
    bool AreCellsFree(QVector<Cell*> cells);
    void FreeCells(QVector<Cell*> cells);

    QList<Enemy*> m_enemies;
    Player* player;
    QVector<QVector<Cell*>> cells;
};

#endif // BOARD_H
