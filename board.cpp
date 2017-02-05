#include "board.h"

Board::Board(QObject *parent) : QObject(parent) {
    qDebug() << "Constructor Board";
    //create x*y cells
    enemy = new Enemy(100, 20);
}

Board::~Board() {
    if ( enemy != nullptr ) {
        delete enemy;
    }
}

Enemy* Board::getEnemy() const {
    return enemy;
}

void Board::setEnemy(Enemy* other) {
    if ( enemy != nullptr ) {
        delete enemy;
    }

    enemy = other;
}
