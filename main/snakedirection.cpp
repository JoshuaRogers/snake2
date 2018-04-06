#include "snakedirection.hpp"
#include "globals.hpp"

Coordinate applyDirection(Coordinate coordinate, SnakeDirection direction)
{
    auto x = coordinate.x;
    auto y = coordinate.y;
    auto z = coordinate.z;

    if (direction == SnakeDirection::X_NEG) {
        x--;
    } else if (direction == SnakeDirection::X_POS) {
        x++;
    } else if (direction == SnakeDirection::Y_NEG) {
        y--;
    } else if (direction == SnakeDirection::Y_POS) {
        y++;
    } else if (direction == SnakeDirection::Z_NEG) {
        z--;
    } else if (direction == SnakeDirection::Z_POS) {
        z++;
    } else {
        log("Attempted to apply invalid snake direction.");
    }

    return Coordinate(x, y, z);
}
