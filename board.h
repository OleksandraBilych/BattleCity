#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <vector>
#include "cell.h"
#include "enemy.h"

class Board : public QObject {
    Q_OBJECT
private:
    std::vector<Cell*> cells;
    const int height = 13;
    const int width = 13;
    QList<Enemy*> enemies;
    Enemy* enemy;

public:
    explicit Board(QObject *parent = 0);
    ~Board();

    Q_PROPERTY(QQmlListProperty<Enemy> enemies READ getEnemies NOTIFY enemiesChanged)
    QQmlListProperty<Enemy> getEnemies();

    Enemy* getEnemy() const;
    void setEnemy(Enemy* other);

signals:
    void enemiesChanged(QQmlListProperty<Enemy>);
};

#endif // BOARD_H


