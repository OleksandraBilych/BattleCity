#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <vector>
#include "cell.h"
#include "enemy.h"

class Board : public QObject {
private:
    std::vector<Cell*> cells;
    const int height = 13;
    const int width = 13;
    Enemy* enemy;

public:
    explicit Board(QObject *parent = 0);
    ~Board();

    Enemy* getEnemy() const;
    void setEnemy(Enemy* other);
};

#endif // BOARD_H


