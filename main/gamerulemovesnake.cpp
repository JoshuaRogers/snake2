#include "gamerulemovesnake.hpp"
#include "game.hpp"
#include "snake.hpp"

void GameRuleMoveSnake::apply(Game* game)
{
    auto snakeIterator = game->getSnakeIterator();
    while (snakeIterator.moveNext()) {
        auto snake = snakeIterator.getValue();
        snake->move();
    }
}