#include "collisionmap.hpp"
#include "snake.hpp"
#include "dot.hpp"
#include "globals.hpp"

CollisionMap::CollisionMap() {
    for (auto i = 0; i < COLLISION_MAP_SIZE; i++) {
        _map[i] = 0;
    }
}

void CollisionMap::markCollision(Coordinate coordinate)
{
    auto index = getMapIndex(coordinate);
    auto offset = getMapOffset(coordinate);
    auto mask = 1 << offset;
    _map[index] |= mask;
}

bool CollisionMap::hasCollision(Coordinate coordinate)
{
    auto index = getMapIndex(coordinate);
    auto offset = getMapOffset(coordinate);
    auto mask = 1 << offset;
    return _map[index] & mask;
}

int CollisionMap::getIndex(Coordinate coordinate)
{
    return coordinate.x * X_SIZE * X_SIZE
         + coordinate.y * Y_SIZE
         + coordinate.z;
}

int CollisionMap::getMapIndex(Coordinate coordinate)
{
    return getIndex(coordinate) / 8;
}

int CollisionMap::getMapOffset(Coordinate coordinate)
{
    return getIndex(coordinate) % 8;
}