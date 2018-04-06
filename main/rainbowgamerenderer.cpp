#include "beta-cube-library.h"

#include "rainbowgamerenderer.hpp"
#include "game.hpp"
#include "snake.hpp"
#include "globals.hpp"

RainbowGameRenderer::RainbowGameRenderer(Cube* cube)
{
    _cube = cube;
}

void RainbowGameRenderer::render(std::shared_ptr<Game> game)
{
    _cube->background(Color());

    auto snakeIterator = game->getSnakeIterator();
    while (snakeIterator.moveNext()) {
        auto snake = snakeIterator.getValue();
        auto coordinateIterator = snake->getCoordinateIterator();

        while (coordinateIterator.moveNext()) {
            auto coordinate = coordinateIterator.getValue();
            _cube->setVoxel(coordinate->x, coordinate->y, coordinate->z, blue);
        }
    }

    _cube->show();
}