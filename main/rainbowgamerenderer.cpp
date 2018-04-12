#include "beta-cube-library.h"

#include "rainbowgamerenderer.hpp"
#include "game.hpp"
#include "snake.hpp"
#include "globals.hpp"

static const Color rainbow[6] = {
    red,
    orange,
    yellow,
    green,
    blue,
    purple
};

RainbowGameRenderer::RainbowGameRenderer(Cube* cube)
{
    _cube = cube;
}

void RainbowGameRenderer::render(std::shared_ptr<Game> game)
{
    _cube->background(black);

    int colorIndex = 0;
    auto snakeIterator = game->getSnakeIterator();
    while (snakeIterator.moveNext()) {
        auto snake = snakeIterator.getValue();
        auto coordinateIterator = snake->getCoordinateIterator();

        auto color = snake->isAlive() ? rainbow[colorIndex] : white;
        while (coordinateIterator.moveNext()) {
            auto coordinate = coordinateIterator.getValue();
            _cube->setVoxel(coordinate.x, coordinate.y, coordinate.z, color);
        }

        colorIndex++;
    }

    _cube->show();
}