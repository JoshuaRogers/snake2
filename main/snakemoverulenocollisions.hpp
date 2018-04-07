#ifndef __SNAKEMOVERULENOCOLLISIONS_HPP__
#define __SNAKEMOVERULENOCOLLISIONS_HPP__

#include "snakemoverule.hpp"

class Game;
class SnakeMoveRuleNoCollisions : public SnakeMoveRule
{
    public:
        SnakeMoveRuleNoCollisions(Game*);
        void apply(Snake*, SnakeMoveEvaluator*) override;

    private:
        Game* _game;
};

#endif