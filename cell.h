#ifndef CELL_H
#define CELL_H

#include <QObject>
#include "boardobject.h"
#include "enums.h"

class CellIsEmptyException {};

class Cell : public QObject
{
public:
    explicit Cell(int x, int y, QObject *parent = 0);
    explicit Cell(int x, int y, BoardObject* obj, QObject *parent = 0);
    ~Cell();

    BoardObject* getBoardObject();
    Objects GetTypeObject();
    void setBoardObject(BoardObject* obj);

    bool isCellEmpty();
    void clearBoardObject();

//private:
    int x;
    int y;
    private:
    bool isEmpty;
    BoardObject* obj;
};

#endif // CELL_H

