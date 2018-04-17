#ifndef __DOT_HPP__
#define __DOT_HPP__

#include "coordinate.hpp"

class Dot
{
    public:
        Dot(Coordinate, unsigned char);
        void ripen();
        Coordinate getCoordinate();
        unsigned char getTicksUntilRipe();
        bool isRipe();

    private:
        Coordinate _coordinate;
        unsigned char _ticksUntilRipe;
};

#endif