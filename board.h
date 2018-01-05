#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <vector>
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

    QQmlListProperty<Enemy> enemies();
    QList<Enemy*> getEnemies();

    Player* getPlayer() const;

signals:
    void enemiesChanged(QQmlListProperty<Enemy>);
    void playerChanged(Player* player);

private:
    QList<Enemy*> m_enemies;
    Player* player;
};

#endif // BOARD_H
