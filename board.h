#ifndef BOARD_H
#define BOARD_H

#include <QObject>

class Board : public QObject {
private:
    const int height = 13;
    const int width = 13;
public:
    explicit Board(QObject *parent = 0);
    ~Board();

};

#endif // BOARD_H
