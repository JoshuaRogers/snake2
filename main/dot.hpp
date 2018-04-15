#ifndef __DOT_HPP__
#define __DOT_HPP__

#include "coordinate.hpp"

class Dot
{
    public:
        Dot(Coordinate);
        Coordinate getCoordinate();

    private:
        Coordinate _coordinate;
};

#endif