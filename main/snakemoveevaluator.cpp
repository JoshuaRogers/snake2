#include <climits>
#include "snakemoveevaluator.hpp"
#include "globals.hpp"

SnakeMoveEvaluator::SnakeMoveEvaluator()
{
    for (auto i = 0; i < DIRECTION_COUNT; i++) {
        _directionsAllowed[i] = true;
        _directionWeights[i] = 0;
    }
}

void SnakeMoveEvaluator::applyWeight(SnakeDirection direction, int weight)
{
    if (direction < 0 || direction >= DIRECTION_COUNT) {
        log("Attempting to apply weight to invalid direction");
    }

    _directionWeights[direction] += weight;
}

void SnakeMoveEvaluator::forbidDirection(SnakeDirection direction)
{
    if (direction < 0 || direction >= DIRECTION_COUNT) {
        log("Attempting to forbid invalid direction");
        return;
    }

    _directionsAllowed[direction] = false;
}

SnakeDirection SnakeMoveEvaluator::chooseDirection()
{
    int bestDirection = SnakeDirection::NONE;
    auto bestWeight = INT_MIN;

    for (auto i = 0; i < DIRECTION_COUNT; i++) {
        auto isDirectionPreferred = _directionWeights[i] > bestWeight;

        if (_directionsAllowed[i] && isDirectionPreferred) {
            bestDirection = i;
            bestWeight = _directionWeights[i];
        }
    }

    return (SnakeDirection)bestDirection;
}
