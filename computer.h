#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <QTimer>

class Computer : public QObject {
    Q_OBJECT
public:
    explicit Computer(QObject *parent = 0);

signals:

public slots:
};

#endif // COMPUTER_H
