#include "snakemoveruledot.hpp"
#include "game.hpp"
#include "snake.hpp"
#include "snakemoveevaluator.hpp"
#include "dot.hpp"
#include "globals.hpp"

// The maximum number of moves that can possibly seperate the snake and the dot.
#define MAX_DISTANCE ((X_SIZE - 1) + (Y_SIZE - 1) + (Z_SIZE - 1))
#define SUCCESS_WEIGHT 255

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

        if (target.x < head.x) {
            moveEvaluator->applyWeight(SnakeDirection::X_NEG, SUCCESS_WEIGHT);
        } else if (target.x > head.x) {
            moveEvaluator->applyWeight(SnakeDirection::X_POS, SUCCESS_WEIGHT);
        }

        if (target.y < head.y) {
            moveEvaluator->applyWeight(SnakeDirection::Y_NEG, SUCCESS_WEIGHT);
        } else if (target.y > head.y) {
            moveEvaluator->applyWeight(SnakeDirection::Y_POS, SUCCESS_WEIGHT);
        }

        if (target.z < head.z) {
            moveEvaluator->applyWeight(SnakeDirection::Z_NEG, SUCCESS_WEIGHT);
        } else if (target.z > head.z) {
            moveEvaluator->applyWeight(SnakeDirection::Z_POS, SUCCESS_WEIGHT);
        }
    }
}