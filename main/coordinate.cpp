#include "coordinate.hpp"

Coordinate::Coordinate()
{

}

Coordinate::Coordinate(int x, int y, int z)
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
