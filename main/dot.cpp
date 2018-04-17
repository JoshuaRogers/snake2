#include "dot.hpp"

Dot::Dot(Coordinate coordinate, unsigned char ticksUntilRipe) : _coordinate(coordinate),
                                                                _ticksUntilRipe(ticksUntilRipe) { }

void Dot::ripen()
{
    if (_ticksUntilRipe > 0) {
        _ticksUntilRipe--;
    }
}

Coordinate Dot::getCoordinate()
{
    return _coordinate;
}

unsigned char Dot::getTicksUntilRipe()
{
    return _ticksUntilRipe;
}

bool Dot::isRipe()
{
    return _ticksUntilRipe == 0;
}