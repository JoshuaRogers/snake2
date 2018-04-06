#include "beta-cube-library.h"
#include "snakemoverulerandom.hpp"
#include "snakemoveevaluator.hpp"

SnakeMoveRuleRandom::SnakeMoveRuleRandom(int magnitude) : _magnitude(magnitude) {}

void SnakeMoveRuleRandom::apply(Snake* snake, SnakeMoveEvaluator* moveEvaluator)
{
    moveEvaluator->applyWeight(SnakeDirection::X_NEG, random(_magnitude));
    moveEvaluator->applyWeight(SnakeDirection::X_POS, random(_magnitude));
    moveEvaluator->applyWeight(SnakeDirection::Y_NEG, random(_magnitude));
    moveEvaluator->applyWeight(SnakeDirection::Y_POS, random(_magnitude));
    moveEvaluator->applyWeight(SnakeDirection::Z_NEG, random(_magnitude));
    moveEvaluator->applyWeight(SnakeDirection::Z_POS, random(_magnitude));
}
