# pragma once

#include <QObject>

class GlobalVariables : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int appWidth READ getAppWidth WRITE setAppWidth NOTIFY AppWidthChanged)
    Q_PROPERTY(int appHeight READ getAppHeight WRITE setAppHeight NOTIFY AppHeightChanged)

public:
    int getAppWidth();
    int getAppHeight();
    int getEnemiesAmount() {return enemiesAmount;}

    void setAppWidth(int value);
    void setAppHeight(int value);

    ~GlobalVariables();
    static GlobalVariables& getInstance();

signals:
    void AppWidthChanged(int value);
    void AppHeightChanged(int value);

private:
    GlobalVariables();

    int appWidth = 850;
    int appHeight = 850;
    const int enemiesAmount = 8;
};
