#include "dot.hpp"

Dot::Dot(Coordinate coordinate) : _coordinate(coordinate) { }

Coordinate Dot::getCoordinate()
{
    return _coordinate;
}