#include "gameruleextendsnake.hpp"

#include "game.hpp"
#include "dot.hpp"
#include "snake.hpp"

void GameRuleExtendSnake::apply(Game* game)
{
    auto dots = game->getDotIterator();
    while (dots.moveNext()) {
        auto dot = dots.getValue();
        auto dotCoordinate = dot->getCoordinate();

        auto snakes = game->getSnakeIterator();
        while (snakes.moveNext()) {
            auto snake = snakes.getValue();
            
            if (!snake->isAlive() || snake->getLength() == 0) {
                continue;
            }

            auto head = snake->getCoordinate(0);
            if (head == dotCoordinate) {
                snake->extend();
                game->removeDot(dot);
            }
        }
    }
}