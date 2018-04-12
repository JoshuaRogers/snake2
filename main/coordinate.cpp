#include "coordinate.hpp"

Coordinate::Coordinate()
{

}

Coordinate::Coordinate(unsigned char x, unsigned char y, unsigned char z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

bool Coordinate::operator==(const Coordinate& coord) const
{
    return x == coord.x
        && y == coord.y
        && z == coord.z;
}
