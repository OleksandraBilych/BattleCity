#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <vector>
#include "cell.h"
#include "enemy.h"

class Board : public QObject {
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Enemy> enemies READ enemies NOTIFY enemiesChanged)

public:
    explicit Board(QObject *parent = 0);
    ~Board();

    QQmlListProperty<Enemy> enemies();
    QList<Enemy*> getEnemies();

signals:
    void enemiesChanged(QQmlListProperty<Enemy>);

private:
    std::vector<Cell*> cells;
    const int height = 13;
    const int width = 13;
    QList<Enemy*> m_enemies;

};

#endif // BOARD_H
