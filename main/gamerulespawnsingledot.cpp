#include "gamerulespawnsingledot.hpp"
#include "snake.hpp"
#include "game.hpp"
#include "dot.hpp"
#include "collisionmap.hpp"

// Even with only one cell available, the probability of finding a cell by choosing at random
// 256 times is 1-(215/216)^256 ~ 70%. With only four cells, it exceeds 99%. While we could
// come up with a more precise way of doing this, this method works well enough for any practical
// case and is one of the easiest on memory.
#define MAX_PLACEMENT_ATTEMPTS 256

GameRuleSpawnSingleDot::GameRuleSpawnSingleDot(int minWaitTicks, int maxWaitTicks) : _minWaitTicks(minWaitTicks),
                                                                                     _maxWaitTicks(maxWaitTicks),
                                                                                     _ticksWithoutDot(0),
                                                                                     _targetWaitTicks((minWaitTicks + maxWaitTicks) / 2) { }

void markCollision(CollisionMap* collisionMap, Iterator<std::shared_ptr<Snake>> snakes)
{
    while (snakes.moveNext()) {
        auto snake = snakes.getValue();
        auto coordinates = snake->getCoordinateIterator();
        while (coordinates.moveNext()) {
            collisionMap->markCollision(coordinates.getValue());
        }
    }
}

CollisionMap buildCollisionMap(Game* game)
{
    auto collisionMap = CollisionMap();
    markCollision(&collisionMap, game->getSnakeIterator());
    return collisionMap;
}

void spawnDot(Game* game)
{
    auto collisionMap = buildCollisionMap(game);

    for (int i = 0; i < MAX_PLACEMENT_ATTEMPTS; i++) {
        auto coordinate = Coordinate(random(X_SIZE),
                                     random(Y_SIZE),
                                     random(Z_SIZE));
        if (!collisionMap.hasCollision(coordinate)) {
            game->addDot(std::make_shared<Dot>(coordinate));
            return;
        }
    }
}

bool hasLivingSnake(Game* game)
{
    auto snakes = game->getSnakeIterator();
    while (snakes.moveNext()) {
        if (snakes.getValue()->isAlive()) {
            return true;
        }
    }

    return false;
}

void GameRuleSpawnSingleDot::apply(Game* game)
{
    if (game->getDotCount() > 0 || !hasLivingSnake(game)) {
        _ticksWithoutDot = 0;
        return;
    }

    if (_ticksWithoutDot == _targetWaitTicks) {
        _targetWaitTicks = random(_maxWaitTicks, _maxWaitTicks);
        _ticksWithoutDot = 0;
        spawnDot(game);
    } else {
        _ticksWithoutDot++;
    }
}
