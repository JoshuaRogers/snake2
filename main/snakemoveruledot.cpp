#include "snakemoveruledot.hpp"
#include "game.hpp"
#include "snake.hpp"
#include "snakemoveevaluator.hpp"
#include "dot.hpp"
#include "globals.hpp"

// The maximum number of moves that can possibly seperate the snake and the dot.
#define MAX_DISTANCE ((X_SIZE - 1) + (Y_SIZE - 1) + (Z_SIZE - 1))
#define SUCCESS_WEIGHT 255

static const SnakeDirection snakeDirections[DIRECTION_COUNT] = {
    SnakeDirection::X_POS,
    SnakeDirection::X_NEG,
    SnakeDirection::Y_POS,
    SnakeDirection::Y_NEG,
    SnakeDirection::Z_POS,
    SnakeDirection::Z_NEG
};

SnakeMoveRuleDot::SnakeMoveRuleDot(Game* game)
{
    _game = game;
}

void approachDot(std::shared_ptr<Dot> dot, Snake* snake, SnakeMoveEvaluator* moveEvaluator) {
        auto target = dot->getCoordinate();
        auto head = snake->getCoordinate(0);

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

void avoidDot(std::shared_ptr<Dot> dot, Snake* snake, SnakeMoveEvaluator* moveEvaluator) {
    auto head = snake->getCoordinate(0);
    for (auto i = 0; i < DIRECTION_COUNT; i++) {
        auto direction = snakeDirections[i];
        auto newHead = applyDirection(head, direction);
        if (newHead == dot->getCoordinate()) {
            moveEvaluator->applyWeight(direction, -SUCCESS_WEIGHT);
        }
    }
}

void SnakeMoveRuleDot::apply(Snake* snake, SnakeMoveEvaluator* moveEvaluator)
{
    auto dots = _game->getDotIterator();
    while (dots.moveNext()) {
        auto dot = dots.getValue();

        if (dot->isRipe()) {
            approachDot(dot, snake, moveEvaluator);
        } else {
            avoidDot(dot, snake, moveEvaluator);
        }
    }
}