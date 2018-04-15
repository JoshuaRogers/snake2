#ifndef __COLLISIONMAP_HPP__
#define __COLLISIONMAP_HPP__

#include "coordinate.hpp"
#include "globals.hpp"

#define COLLISION_MAP_SIZE (X_SIZE * Y_SIZE * Z_SIZE / 8) + 1

class CollisionMap {
    public:
        CollisionMap();
        void markCollision(Coordinate);
        bool hasCollision(Coordinate);
    private:
        int getIndex(Coordinate);
        int getMapIndex(Coordinate);
        int getMapOffset(Coordinate);
        unsigned char _map[COLLISION_MAP_SIZE];
};

#endif