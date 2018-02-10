#include "board.h"
#include <QGuiApplication>
#include <QScreen>
#include <QWindow>

const int step = 10;

Board::Board(QObject *parent) : QObject(parent)
{
    qDebug() << "Constructor Board";

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    // divide the board into cells
    int rowsAmount = height / step;
    if (height % step != 0)
        rowsAmount += 1;

    int columnsAmount = width / step;
    if (width % step != 0)
        columnsAmount += 1;

    cells.resize(rowsAmount);
    for (int row = 0; row < rowsAmount; row++) {
        for(int col = 0; col < columnsAmount; col++) {
            cells[row].append(new Cell(row * step, col * step));
        }
    }

    //create enemy tanks
    int enemiesAmount = 6; // TO DO: move to commmon config
    int distance = width/enemiesAmount;

    for (int i = 0; i < enemiesAmount; i++) {
        Enemy* enemy = new Enemy(100, 20, distance * i + distance / 2, 0);
        m_enemies.append(enemy);

        int firstRow = 0;
        int firstCol = (distance * i + distance / 2) / step;
        rowsAmount = enemy->getHeight() / step;
        columnsAmount = enemy->getWidth() / step;

        for (int row = 0; row < rowsAmount; row++) {
            for(int col = 0; col < columnsAmount; col++) {
                 cells[firstRow + row][firstCol + col]->setBoardObject(enemy);
            }
        }
    }

    //create player's tank
    int playerX = width / 2 - 50;
    int playerY = height - 150;
    player.reset(new Player(100, 20, "PlayerTank", playerX, playerY));

    int firstRow = playerY / step;
    int firstCol = playerX / step;
    rowsAmount = player->getHeight() / step;
    columnsAmount = player->getWidth() / step;

    for (int row = 0; row < rowsAmount; row++) {
        for(int col = 0; col < columnsAmount; col++) {
            cells[firstRow + row][firstCol + col]->setBoardObject(player.data());
        }
    }
}

Board::~Board()
{
    qDeleteAll(m_enemies);
    m_enemies.clear();

    foreach(QVector<Cell*> cell, cells)
        qDeleteAll(cell);
    cells.clear();

    qDeleteAll(m_bullets);
    m_bullets.clear();
}

bool Board::AreCellsFree(QVector<Cell*> cells)
{
    // check if cells are avaliable
    bool areFree = true;

    for (auto& cell : cells) {
        if (!cell->isCellEmpty()) {
            areFree = false;
            break;
        }
    }

    return areFree;
}

void Board::FreeCells(QVector<Cell*> cells)
{
    for (auto& cell : cells)
        cell->clearBoardObject();
}

QVector<QVector<Cell*>> Board::calcPrevAndNextCells(BoardObject* object)
{
    QVector<Cell*> prevCells, nextCells;
    QVector<QVector<Cell*>> prevNextCells;

    int direction = object->getDirection();
    int firstRow = object->getY() / step;
    int firstCol = object->getX() / step;
    int nextIndex = 0;
    int prevIndex = 0;

    //calculate indexes next and previous cells
    if ( direction == Direction::dir_down) {
        prevIndex = firstRow;
        nextIndex = firstRow + object->getHeight() / step;
    } else if (direction == Direction::dir_up) {
        prevIndex = firstRow + object->getHeight() / step - 1;
        nextIndex = firstRow - 1;
    } else if (direction == Direction::dir_left) {
        prevIndex = firstCol + object->getWidth() / step - 1;
        nextIndex = firstCol - 1;
    } else if (direction == Direction::dir_right) {
        nextIndex = firstCol + object->getWidth() / step;
        prevIndex = firstCol;
    }

    if ( direction == Direction::dir_down || direction == Direction::dir_up) {
        int cellAmount = object->getWidth() / step;
        for (int cell = 0; cell < cellAmount; cell++)
            prevCells.append(cells[prevIndex][firstCol + cell]);

        prevNextCells.append(prevCells);

        //check colision with window borders
        if (nextIndex * step >= qApp->focusWindow()->height() ||
            nextIndex * step < 0)
            return prevNextCells;

        for (int cell = 0; cell < cellAmount; cell++)
            nextCells.append(cells[nextIndex][firstCol + cell]);
    } else {
        int cellAmount = object->getHeight() / step;
        for (int cell = 0; cell < cellAmount; cell++)
            prevCells.append(cells[firstRow + cell][prevIndex]);

        prevNextCells.append(prevCells);

        //check colision with window borders
        if (nextIndex * step >= qApp->focusWindow()->width() ||
            nextIndex * step < 0)
            return prevNextCells;

        for (int cell = 0; cell < cellAmount; cell++)
            nextCells.append(cells[firstRow + cell][nextIndex]);
    }

    prevNextCells.append(nextCells);

    return prevNextCells;
}

Objects Board::IdentifyObjectType(QVector<Cell*> objectCells)
{
    Objects type = Objects::undefined;

    for (auto& cell : objectCells) {
        if (!cell->isCellEmpty())
            type = cell->GetTypeObject();
    }

    return type;
}

Objects Board::move(Tank* tank)
{
    // check if a cell is avaliable
    // if it's not than don't move the tank
    QVector<QVector<Cell*>> prevNextCells = calcPrevAndNextCells(tank);
    if (prevNextCells.size() == 1)
        return Objects::windowBorders;

    // if new cells are avaliable the tank make a step
    // otherwise the tank change direction
    if (AreCellsFree(prevNextCells[1])) {
        for (auto& cell : prevNextCells[1])
            cell->setBoardObject(tank);
        FreeCells(prevNextCells[0]);

        return Objects::emptyCell;
    }

    return IdentifyObjectType(prevNextCells[1]);
}

Objects Board::move(Bullet* bullet)
{
    QVector<QVector<Cell*>> prevNextCells = calcPrevAndNextCells(bullet);

    // if we couldn't calculate next cells
    // than we have collision with window borders
    if (prevNextCells.size() == 1) {
        FreeCells(prevNextCells[0]);
        return Objects::windowBorders;
    }

    if (AreCellsFree(prevNextCells[1])) {
        for (auto& cell : prevNextCells[1])
            cell->setBoardObject(bullet);
        FreeCells(prevNextCells[0]);

        return Objects::emptyCell;
    }

    return IdentifyObjectType(prevNextCells[1]);
}

void Board::addBullet(Bullet* bullet)
{
    m_bullets.append(bullet);

    int col = bullet->getX() / step;
    int row = bullet->getY() / step;

    Cell* cell = cells.at(row).at(col);
    cell->setBoardObject(bullet);

    emit bulletsChanged(bullets());
}

void Board::removeBullet(Bullet *bullet)
{
    m_bullets.removeOne(bullet);
    emit bulletsChanged(bullets());
}


QQmlListProperty<Enemy> Board::enemies()
{
    return QQmlListProperty<Enemy>(this, m_enemies);
}

QList<Enemy*> Board::getEnemies()
{
    return m_enemies;
}

Player* Board::getPlayer() const
{
    return player.data();
}

QQmlListProperty<Bullet> Board::bullets()
{
    return QQmlListProperty<Bullet>(this, m_bullets);
}

QList<Bullet*> Board::getBullets()
{
    return m_bullets;
}
