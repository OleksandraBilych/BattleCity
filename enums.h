#ifndef ENUMS_H
#define ENUMS_H

enum Direction
{
    dir_left = 270,
    dir_right = 90,
    dir_up = 0,
    dir_down = 180
};

enum Objects
{
    wall = 1,
    tank = 2,
    bullet = 3,
    emptyCell = 4,
    windowBorders = 5,
    undefined = -1
};

#endif // ENUMS_H


