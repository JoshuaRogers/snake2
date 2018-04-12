#include "snakemoverulestraight.hpp"
#include "snake.hpp"
#include "snakemoveevaluator.hpp"

#define MIN_BODY_SEGMENTS 2
#define SUCCESS_WEIGHT 255

void SnakeMoveRuleStraight::apply(Snake* snake, SnakeMoveEvaluator* moveEvaluator)
{
    if (snake->getLength() < MIN_BODY_SEGMENTS) {
        return;
    }

    auto head = snake->getCoordinate(0);
    auto neck = snake->getCoordinate(1);

    if (head.x < neck.x) {
        moveEvaluator->applyWeight(SnakeDirection::X_NEG, SUCCESS_WEIGHT);
    } else if (head.x > neck.x) {
        moveEvaluator->applyWeight(SnakeDirection::X_POS, SUCCESS_WEIGHT);
    } else if (head.y < neck.y) {
        moveEvaluator->applyWeight(SnakeDirection::Y_NEG, SUCCESS_WEIGHT);
    } else if (head.y > neck.y) {
        moveEvaluator->applyWeight(SnakeDirection::Y_POS, SUCCESS_WEIGHT);
    } else if (head.z < neck.z) {
        moveEvaluator->applyWeight(SnakeDirection::Z_NEG, SUCCESS_WEIGHT);
    } else if (head.z > neck.z) {
        moveEvaluator->applyWeight(SnakeDirection::Z_POS, SUCCESS_WEIGHT);
    }
}
