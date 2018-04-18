#include "beta-cube-library.h"
#include "graphicsdriver.hpp"

#include "rainbowgamerenderer.hpp"
#include "game.hpp"
#include "snake.hpp"
#include "dot.hpp"
#include "globals.hpp"

#define SATURATION 1
#define VALUE      0.5

RainbowGameRenderer::RainbowGameRenderer(GraphicsDriver* graphics) : _graphics(graphics),
                                                                     _tick(0) { }

void RainbowGameRenderer::renderSnake(std::shared_ptr<Snake> snake)
{
    auto coordinateIterator = snake->getCoordinateIterator();
    auto coordinateIndex = 0;
    while (coordinateIterator.moveNext()) {
        auto hue = (_tick - coordinateIndex) * 2;
        auto color = snake->isAlive() ? GraphicsDriver::fromHSV(hue, SATURATION, VALUE) : grey;
        auto coordinate = coordinateIterator.getValue();

        _graphics->setVoxel(coordinate.x, coordinate.y, coordinate.z, color);
        coordinateIndex++;
    }

    _tick++;
}

void RainbowGameRenderer::render(std::shared_ptr<Game> game)
{
    _graphics->flip();
    _graphics->clear();

    auto snakeIterator = game->getSnakeIterator();
    while (snakeIterator.moveNext()) {
        auto snake = snakeIterator.getValue();
        renderSnake(snake);
    }

    auto dotIterator = game->getDotIterator();
    while (dotIterator.moveNext()) {
        auto coordinate = dotIterator.getValue()->getCoordinate();
        _graphics->setVoxel(coordinate.x, coordinate.y, coordinate.z, white);
    }
}