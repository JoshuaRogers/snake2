#include <memory>
#include <climits>
#include "coordinate.hpp"
#include "snake.hpp"
#include "snakemoveevaluator.hpp"
#include "snakemoverule.hpp"

Snake::Snake(Coordinate initialCoordinate, int targetLength)
{
    for(int i = 0; i < targetLength; i++) {
        _coordinates.add(std::make_shared<Coordinate>(initialCoordinate));
    }
}

Iterator<Coordinate> Snake::getCoordinateIterator()
{
    return _coordinates.getIterator();
}

void Snake::move()
{
    auto moveEvaluator = SnakeMoveEvaluator();
    auto ruleIterator = _moveRules.getIterator();

    while (ruleIterator.moveNext()) {
        auto rule = ruleIterator.getValue();
        rule->apply(this, &moveEvaluator);
    }

    auto direction = moveEvaluator.chooseDirection();
    if (direction == SnakeDirection::NONE) {
        // @Todo: Snake should die if no move is available. Return bool?
        return;
    }

    auto head = _coordinates.get(0);
    auto newHead = applyDirection(*head.get(), direction);
    _coordinates.add(std::make_shared<Coordinate>(newHead), 0);
    _coordinates.remove(_coordinates.getLength() - 1);
}

void Snake::addMoveRule(std::shared_ptr<SnakeMoveRule> rule)
{
    _moveRules.add(rule);
}

std::shared_ptr<Coordinate> Snake::getCoordinate(int index)
{
    return _coordinates.get(index);
}

int Snake::getLength()
{
    return _coordinates.getLength();
}
