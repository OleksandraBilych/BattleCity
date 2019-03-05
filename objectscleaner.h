#ifndef OBJECTSCLEANER_H
#define OBJECTSCLEANER_H

#include <QObject>
#include <QTimer>

#include "board.h"
#include "boardobject.h"

class ObjectsCleaner : public QObject
{
    Q_OBJECT

public:
    ~ObjectsCleaner();

    void setBoard(Board* board);

    bool isDeadObjectOnBoard();
    QVector<BoardObject*> deadObjects();

    void startTimer();
    void stopTimer();

    static ObjectsCleaner* getInstance(QObject *parent = nullptr, Board *board = nullptr);

public slots:
    void launchCleaner(bool signOfLife);
    void deleteObjects();

private:
    explicit ObjectsCleaner(QObject *parent = nullptr, Board *board = nullptr);

private:
    QScopedPointer<QTimer> timer;
    Board* board;

    static ObjectsCleaner* instance;
};

#endif // OBJECTSCLEANER_H
