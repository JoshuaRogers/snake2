#include <memory>
#include <climits>
#include "coordinate.hpp"
#include "snake.hpp"
#include "snakemoveevaluator.hpp"
#include "snakemoverule.hpp"

Snake::Snake(int snakeId, Coordinate initialCoordinate, int targetLength) : _snakeId(snakeId),
                                                                            _isAlive(true)
{
    for(int i = 0; i < targetLength; i++) {
        _coordinates.add(initialCoordinate);
    }
}

Iterator<Coordinate> Snake::getCoordinateIterator()
{
    return _coordinates.getIterator();
}

void Snake::move()
{
    if (isAlive()) {
        tryMove() || die();
    } else {
        dissolve();
    }
}

void Snake::extend()
{
    auto head = getLength() >= 0
        ? getCoordinate(0)
        : Coordinate(0, 0, 0);
    _coordinates.add(head, 0);
}

void Snake::addMoveRule(std::shared_ptr<SnakeMoveRule> rule)
{
    _moveRules.add(rule);
}

Coordinate Snake::getCoordinate(int index)
{
    return _coordinates.get(index);
}

int Snake::getLength()
{
    return _coordinates.getLength();
}

int Snake::getId()
{
    return _snakeId;
}

bool Snake::isAlive()
{
    return _isAlive;
}

bool Snake::die()
{
    return _isAlive = false;
}

SnakeDirection Snake::chooseDirection()
{
    auto moveEvaluator = SnakeMoveEvaluator();
    auto ruleIterator = _moveRules.getIterator();

    while (ruleIterator.moveNext()) {
        auto rule = ruleIterator.getValue();
        rule->apply(this, &moveEvaluator);
    }

    return moveEvaluator.chooseDirection();
}

bool Snake::tryMove()
{
    auto direction = chooseDirection();
    if (direction == SnakeDirection::NONE) {
        return false;
    }

    auto head = _coordinates.get(0);
    auto newHead = applyDirection(head, direction);
    _coordinates.add(newHead, 0);
    _coordinates.remove(_coordinates.getLength() - 1);
    return true;
}

void Snake::dissolve()
{
    if (_coordinates.getLength() > 0) {
        _coordinates.remove(0);
    }
}
