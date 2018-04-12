#ifndef __COORDINATE_HPP
#define __COORDINATE_HPP

class Coordinate
{
    public:
        Coordinate();
        Coordinate(int x, int y, int z);
        int x;
        int y;
        int z;
        bool operator==(const Coordinate&) const;
};

#endif