#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QQmlListProperty>
#include <vector>
#include "cell.h"
#include "enemy.h"

class Board : public QObject {
    Q_OBJECT
private:
    std::vector<Cell*> cells;
    const int height = 13;
    const int width = 13;
    QList<Enemy*> m_enemies;

public:
    explicit Board(QObject *parent = 0);
    ~Board();

    Q_PROPERTY(QQmlListProperty<Enemy> enemies READ enemies NOTIFY enemiesChanged)
    Q_CLASSINFO("DefaultProperty", "enemies")

    QQmlListProperty<Enemy> enemies();
    Q_INVOKABLE void add();
    QList<Enemy *> getEnemies();

signals:
    void enemiesChanged();

private:
    static void append_enemy(QQmlListProperty<Enemy> *list, Enemy *enemy);
};

#endif // BOARD_H

