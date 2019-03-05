# pragma once

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
    enemy = 2,
    player = 3,
    bullet = 4,
    emptyCell = 5,
    windowBorders = 6,
    playersBase = 7,
    undefined = -1
};
