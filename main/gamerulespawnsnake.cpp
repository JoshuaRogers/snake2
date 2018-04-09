#include "game.hpp"
#include "gamerulespawnsnake.hpp"
#include "snake.hpp"

#include "snakemoveruleinbounds.hpp"
#include "snakemoverulerandom.hpp"
#include "snakemoverulestraight.hpp"
#include "snakemoverulenocollisions.hpp"

GameRuleSpawnSnake::GameRuleSpawnSnake(int targetSnakeCount) : _targetSnakeCount(targetSnakeCount)
{
}

void GameRuleSpawnSnake::apply(Game* game)
{
    if (game->getSnakeCount() < _targetSnakeCount)
    {
        auto initialCoordinate = Coordinate(0, 0, 0);
        auto snake = std::make_shared<Snake>(Snake(initialCoordinate, 14));
        snake->addMoveRule(std::make_shared<SnakeMoveRuleInBounds>(SnakeMoveRuleInBounds(0, 0, 0, X_SIZE - 1, Y_SIZE - 1, Z_SIZE - 1)));
        snake->addMoveRule(std::make_shared<SnakeMoveRuleNoCollisions>(SnakeMoveRuleNoCollisions(game)));
        snake->addMoveRule(std::make_shared<SnakeMoveRuleRandom>(SnakeMoveRuleRandom(6)));
        snake->addMoveRule(std::make_shared<SnakeMoveRuleStraight>(SnakeMoveRuleStraight()));
        game->addSnake(snake);
    }    
}
