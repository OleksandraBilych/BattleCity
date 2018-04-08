#include "cell.h"
#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include <typeinfo>

Cell::Cell(int x, int y, QObject *parent)
    : QObject(parent), x(x), y(y), isEmpty(true), obj(nullptr)
{
}

Cell::Cell(int x, int y, BoardObject* obj, QObject *parent)
    : QObject(parent), x(x), y(y), isEmpty(false), obj(obj)
{
}

Cell::~Cell()
{
}

BoardObject* Cell::getBoardObject()
{
    return obj;
}

Objects Cell::GetTypeObject()
{
    if (typeid(*obj) == typeid(Bullet))
        return Objects::bullet;
    else if (typeid(*obj) == typeid(Enemy))
        return Objects::enemy;
    else if (typeid(*obj) == typeid(Player))
        return Objects::player;

    return Objects::undefined;
}

void Cell::setBoardObject(BoardObject* obj)
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
