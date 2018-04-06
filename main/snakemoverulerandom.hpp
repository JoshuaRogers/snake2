#ifndef __SNAKEMOVERULERANDOM_HPP__
#define __SNAKEMOVERULERANDOM_HPP__

#include "snakemoverule.hpp"

class SnakeMoveRuleRandom : public SnakeMoveRule
{
    public:
        SnakeMoveRuleRandom(int magnitude);
        void apply(Snake*, SnakeMoveEvaluator*) override;

    private:
        int _magnitude;
};

#endif