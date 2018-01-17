#include "cell.h"

Cell::Cell(int x, int y, QObject *parent)
    : QObject(parent), x(x), y(y), isEmpty(true), obj(nullptr)
{
}

Cell::Cell(int x, int y, const BoardObject* obj, QObject *parent)
    : QObject(parent), x(x), y(y), isEmpty(false), obj(obj)
{
    qDebug() << "Constructor: Cell";
}

Cell::~Cell()
{
    qDebug() << "Destructor: Cell";
}

const BoardObject* Cell::getBoardObject()
{
    return obj;
}

void Cell::setBoardObject(const BoardObject* obj)
{
    if (this->obj == obj)
        return;

    this->obj = obj;
    isEmpty = false;
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
