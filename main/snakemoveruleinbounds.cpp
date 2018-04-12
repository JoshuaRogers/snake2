#include "snakemoveruleinbounds.hpp"
#include "snake.hpp"
#include "snakemoveevaluator.hpp"

SnakeMoveRuleInBounds::SnakeMoveRuleInBounds(int minx, int miny, int minz, int maxx, int maxy, int maxz) : _minx(minx), _miny(miny), _minz(minz),
    _maxx(maxx), _maxy(maxy), _maxz(maxz)  {}

void SnakeMoveRuleInBounds::apply(Snake* snake, SnakeMoveEvaluator* moveEvaluator)
{
    if (snake->getLength() == 0) {
        return;
    }

    auto head = snake->getCoordinate(0);
    if (head.x <= _minx) {
        moveEvaluator->forbidDirection(SnakeDirection::X_NEG);
    }
    if (head.x >= _maxx) {
        moveEvaluator->forbidDirection(SnakeDirection::X_POS);
    }
    if (head.y <= _miny) {
        moveEvaluator->forbidDirection(SnakeDirection::Y_NEG);
    }
    if (head.y >= _maxy) {
        moveEvaluator->forbidDirection(SnakeDirection::Y_POS);
    }
    if (head.z <= _minz) {
        moveEvaluator->forbidDirection(SnakeDirection::Z_NEG);
    }
    if (head.z >= _maxz) {
        moveEvaluator->forbidDirection(SnakeDirection::Z_POS);
    }
}
