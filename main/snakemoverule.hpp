#ifndef __SNAKEMOVERULE_HPP__
#define __SNAKEMOVERULE_HPP__

#include <memory>

class Snake;
class SnakeMoveEvaluator;
class SnakeMoveRule
{
    public:
        virtual void apply(Snake*, SnakeMoveEvaluator*) = 0;
};

#endif