#ifndef CELL_H
#define CELL_H

#include <QObject>
#include "boardobject.h"

class CellIsEmptyException {};

class Cell : public QObject
{
public:
    explicit Cell(int x, int y, QObject *parent = 0);
    explicit Cell(int x, int y, const BoardObject* obj, QObject *parent = 0);
    ~Cell();

    const BoardObject* getBoardObject();
    void setBoardObject(const BoardObject* obj);

    bool isCellEmpty();
    void clearBoardObject();

//private:
    int x;
    int y;
    private:
    bool isEmpty;
    const BoardObject* obj;
};

#endif // CELL_H

