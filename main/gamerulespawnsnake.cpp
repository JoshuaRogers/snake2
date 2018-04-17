#include "game.hpp"
#include "gamerulespawnsnake.hpp"
#include "snake.hpp"
#include "snakefactory.hpp"

#define INITIAL_LENGTH 3

GameRuleSpawnSnake::GameRuleSpawnSnake(std::shared_ptr<SnakeFactory> snakeFactory, int targetSnakeCount) : _snakeFactory(snakeFactory),
                                                                                                           _targetSnakeCount(targetSnakeCount) { }

void GameRuleSpawnSnake::apply(Game* game)
{
    if (game->getSnakeCount() < _targetSnakeCount)
    {
        auto initialCoordinate = Coordinate(0, 0, 0);
        auto snake = _snakeFactory->build(initialCoordinate, INITIAL_LENGTH);
        game->addSnake(snake);
    }
}
