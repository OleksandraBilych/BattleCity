#include "globalvariables.h"

#include <QDebug>

GlobalVariables::GlobalVariables()
{

}

GlobalVariables::~GlobalVariables()
{
    if (!instance.isNull())
        instance.clear();
}

int GlobalVariables::getAppWidth()
{
    return appWidth;
}

int GlobalVariables::getAppHeight()
{
    return appHeight;
}

void GlobalVariables::setAppWidth(int value)
{
    if (appWidth != value)
        appWidth = value;
}

void GlobalVariables::setAppHeight(int value)
{
    if (appHeight != value)
        appHeight = value;
}

QSharedPointer<GlobalVariables> GlobalVariables::instance =
        QSharedPointer<GlobalVariables>();

QSharedPointer<GlobalVariables> GlobalVariables::getInstance()
{
    if (instance.isNull())
        instance = QSharedPointer<GlobalVariables>(new GlobalVariables());

    return instance;
}
