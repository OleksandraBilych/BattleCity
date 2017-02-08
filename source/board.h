#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <vector>
#include "enemy.h"

class Board : public QObject {
    Q_OBJECT

private:
    Enemy* enemy;

public:
    explicit Board(QObject *parent = 0);
    ~Board();

    Enemy* getEnemy() const;
    void setEnemy(Enemy* other);
};

#endif // BOARD_H


