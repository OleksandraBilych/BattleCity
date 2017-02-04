#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <vector>
#include "cell.h"

class Board : public QObject {
private:
    std::vector<Cell*> cells;
    const int height = 13;
    const int width = 13;

public:
    explicit Board(QObject *parent = 0);
    ~Board();

};

#endif // BOARD_H
