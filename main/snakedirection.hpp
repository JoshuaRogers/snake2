#ifndef __SNAKEDIRECTIONS_HPP__
#define __SNAKEDIRECTIONS_HPP__

#include "coordinate.hpp"

#define DIRECTION_COUNT 6

enum SnakeDirection
{
    NONE = -1,
    X_POS = 0,
    X_NEG = 1,
    Y_POS = 2,
    Y_NEG = 3,
    Z_POS = 4,
    Z_NEG = 5
};

Coordinate applyDirection(Coordinate coordinate, SnakeDirection direction);

#endif