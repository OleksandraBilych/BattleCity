#include "globalvariables.h"

#include <QDebug>

GlobalVariables::GlobalVariables()
{

}

GlobalVariables::~GlobalVariables()
{
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

GlobalVariables& GlobalVariables::getInstance()
{
    static GlobalVariables instance;

    return instance;
}
