#include "snakemoveruledot.hpp"
#include "game.hpp"
#include "snake.hpp"
#include "snakemoveevaluator.hpp"
#include "dot.hpp"
#include "globals.hpp"

// The maximum number of moves that can possibly seperate the snake and the dot.
#define MAX_DISTANCE ((X_SIZE - 1) + (Y_SIZE - 1) + (Z_SIZE - 1))
#define MAX_WEIGHT 256

SnakeMoveRuleDot::SnakeMoveRuleDot(Game* game)
{
    _game = game;
}

void SnakeMoveRuleDot::apply(Snake* snake, SnakeMoveEvaluator* moveEvaluator)
{
    auto head = snake->getCoordinate(0);
    auto dots = _game->getDotIterator();
    while (dots.moveNext()) {
        auto dot = dots.getValue();
        auto target = dot->getCoordinate();

        auto distance = abs(head.x - target.x) + abs(head.y - target.y) + abs(head.z - target.z);
        auto weight = 1.0 - (double(distance) / MAX_DISTANCE);
        auto scaledWeight = weight * MAX_WEIGHT;

        if (target.x < head.x) {
            moveEvaluator->applyWeight(SnakeDirection::X_NEG, scaledWeight);
        } else if (target.x > head.x) {
            moveEvaluator->applyWeight(SnakeDirection::X_POS, scaledWeight);
        }

        if (target.y < head.y) {
            moveEvaluator->applyWeight(SnakeDirection::Y_NEG, scaledWeight);
        } else if (target.y > head.y) {
            moveEvaluator->applyWeight(SnakeDirection::Y_POS, scaledWeight);
        }

        if (target.z < head.z) {
            moveEvaluator->applyWeight(SnakeDirection::Z_NEG, scaledWeight);
        } else if (target.z > head.z) {
            moveEvaluator->applyWeight(SnakeDirection::Z_POS, scaledWeight);
        }
    }
}