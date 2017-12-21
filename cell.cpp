#include "cell.h"

Cell::Cell(int x, int y, QObject *parent)
    : QObject(parent), x(x), y(y), isEmpty(true), obj(nullptr)
{
    qDebug() << "Constructor: Cell";
}

Cell::Cell(int x, int y, BoardObject* obj, QObject *parent)
    : QObject(parent), x(x), y(y), isEmpty(true), obj(obj)
{
    qDebug() << "Constructor: Cell";
}

Cell::~Cell()
{
    qDebug() << "Destructor: Cell";
}

BoardObject* Cell::getBoardObject()
{
    return obj;
}

void Cell::setBoardObject(BoardObject* obj)
{
    this->obj = obj;
}

bool Cell::isCellEmpty()
{
    return isEmpty;
}

void Cell::clearBoardObject()
{
    if ( !isEmpty )
        throw CellIsEmptyException();

    obj = nullptr;
    isEmpty = true;
}
