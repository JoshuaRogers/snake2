#include "gameruleprunedeadsnake.hpp"
#include "game.hpp"
#include "snake.hpp"

void GameRulePruneDeadSnake::apply(Game* game)
{
    auto snakes = game->getSnakeIterator();
    while (snakes.moveNext()) {
        auto snake = snakes.getValue();
        if (!snake->isAlive() && snake->getLength() == 0) {
            game->removeSnake(snake);
        }
    }
}
