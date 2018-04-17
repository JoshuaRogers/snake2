#include "snakefactory.hpp"
#include "snake.hpp"

SnakeFactory::SnakeFactory() : _snakeId(0) { }

void SnakeFactory::addMoveRule(std::shared_ptr<SnakeMoveRule> rule)
{
    _rules.add(rule);
}

std::shared_ptr<Snake> SnakeFactory::build(Coordinate head, int length)
{
    auto snake = std::make_shared<Snake>(Snake(_snakeId, head, length));

    auto rules = _rules.getIterator();
    while (rules.moveNext()) {
        auto rule = rules.getValue();
        snake->addMoveRule(rule);
    }

    _snakeId++;
    return snake;
}
