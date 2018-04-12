#include "snakemoverulenocollisions.hpp"
#include "game.hpp"
#include "globals.hpp"
#include "snake.hpp"
#include "snakedirection.hpp"
#include "snakemoveevaluator.hpp"

static const SnakeDirection snakeDirections[DIRECTION_COUNT] = {
    SnakeDirection::X_POS,
    SnakeDirection::X_NEG,
    SnakeDirection::Y_POS,
    SnakeDirection::Y_NEG,
    SnakeDirection::Z_POS,
    SnakeDirection::Z_NEG
};

SnakeMoveRuleNoCollisions::SnakeMoveRuleNoCollisions(Game* game) : _game(game) {}

bool hasCollision(std::shared_ptr<Snake> snake, Coordinate candidateCoordinate) {
    auto snakeCoordinates = snake->getCoordinateIterator();
    while (snakeCoordinates.moveNext()) {
        auto snakeCoordinate = snakeCoordinates.getValue();
        if (snakeCoordinate == candidateCoordinate) {
            return true;
        }
    }

    return false;
}

bool hasCollision(Game* game, Coordinate candidateCoordinate) {
    auto snakes = game->getSnakeIterator();
    while (snakes.moveNext()) {
        auto snake = snakes.getValue();
        if (hasCollision(snake, candidateCoordinate)) {
            return true;
        }
    }

    return false;
}

void SnakeMoveRuleNoCollisions::apply(Snake* snake, SnakeMoveEvaluator* moveEvaluator)
{
    if (snake->getLength() == 0) {
        log("Testing for snake collision of snake with zero length.");
        return;
    }

    auto head = snake->getCoordinate(0);

    for (int i = 0; i < DIRECTION_COUNT; i++) {
        auto direction = snakeDirections[i];
        auto directionCoordinate = applyDirection(head, direction);

        if (hasCollision(_game, directionCoordinate)) {
            moveEvaluator->forbidDirection(direction);
        }
    }
}
