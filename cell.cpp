#include "cell.h"

Cell::Cell(int x, int y, QObject *parent)
    : QObject(parent), x(x), y(y), isEmpty(true), obj(nullptr)
{
}

Cell::Cell(int x, int y, BoardObject* obj, QObject *parent)
    : QObject(parent), x(x), y(y), isEmpty(false), obj(obj)
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
    if (this->obj == obj)
        return;

    this->obj = obj;
    isEmpty = false;

    qDebug() << "obj: x - " << obj->getX() << ", y - " << obj->getY();
}

bool Cell::isCellEmpty()
{
    return isEmpty;
}

void Cell::clearBoardObject()
{
    obj = nullptr;
    isEmpty = true;
}
