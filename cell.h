#ifndef CELL_H
#define CELL_H

#include <QObject>
#include "boardobject.h"

class CellIsEmptyException {};

class Cell : public QObject {
private:
    int x;
    int y;
    bool isEmpty;
    BoardObject* obj;

public:
    explicit Cell(int x, int y, QObject *parent = 0);
    explicit Cell(int x, int y, BoardObject* obj, QObject *parent = 0);
    ~Cell();

    BoardObject* getBoardObject();
    void setBoardObject(BoardObject* obj);

    bool isCellEmpty();
    void clearBoardObject();
};

#endif // CELL_H
