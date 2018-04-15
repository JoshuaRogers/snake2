#include "beta-cube-library.h"
#include "graphicsdriver.hpp"

#include "rainbowgamerenderer.hpp"
#include "game.hpp"
#include "snake.hpp"
#include "dot.hpp"
#include "globals.hpp"

static const Color rainbow[6] = {
    red,
    orange,
    yellow,
    green,
    blue,
    purple
};

RainbowGameRenderer::RainbowGameRenderer(GraphicsDriver* graphics) : _graphics(graphics) { }

void RainbowGameRenderer::render(std::shared_ptr<Game> game)
{
    _graphics->flip();
    _graphics->clear();

    int colorIndex = 0;
    auto snakeIterator = game->getSnakeIterator();
    while (snakeIterator.moveNext()) {
        auto snake = snakeIterator.getValue();
        auto coordinateIterator = snake->getCoordinateIterator();

        auto color = snake->isAlive() ? rainbow[colorIndex] : white;
        while (coordinateIterator.moveNext()) {
            auto coordinate = coordinateIterator.getValue();
            _graphics->setVoxel(coordinate.x, coordinate.y, coordinate.z, color);
        }

        colorIndex++;
    }

    auto dotIterator = game->getDotIterator();
    while (dotIterator.moveNext()) {
        auto coordinate = dotIterator.getValue()->getCoordinate();
        _graphics->setVoxel(coordinate.x, coordinate.y, coordinate.z, white);
    }
}