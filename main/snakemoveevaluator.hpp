#ifndef __SNAKEMOVEEVALUATOR_HPP__
#define __SNAKEMOVEEVALUATOR_HPP__

#include "snakedirection.hpp"

class SnakeMoveEvaluator
{
    public:
        SnakeMoveEvaluator();
        void applyWeight(SnakeDirection, int);
        void forbidDirection(SnakeDirection);
        SnakeDirection chooseDirection();

    private:
        int _directionsAllowed[DIRECTION_COUNT];
        int _directionWeights[DIRECTION_COUNT]; 
};

#endif