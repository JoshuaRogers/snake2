#ifndef __SNAKEMOVERULESTRAIGHT_HPP__
#define __SNAKEMOVERULESTRAIGHT_HPP__

#include "snakemoverule.hpp"

class SnakeMoveRuleStraight : public SnakeMoveRule
{
    public:
        void apply(Snake*, SnakeMoveEvaluator*) override;
};

#endif