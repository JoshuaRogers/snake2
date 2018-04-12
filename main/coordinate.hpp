#ifndef __COORDINATE_HPP
#define __COORDINATE_HPP

class Coordinate
{
    public:
        Coordinate();
        Coordinate(unsigned char x, unsigned char y, unsigned char z);
        unsigned char x;
        unsigned char y;
        unsigned char z;
        bool operator==(const Coordinate&) const;
};

#endif