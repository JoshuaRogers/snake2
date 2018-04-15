#ifndef __SNAKEMOVERULEDOT_HPP__
#define __SNAKEMOVERULEDOT_HPP__

#include "snakemoverule.hpp"

class Game;
class SnakeMoveRuleDot : public SnakeMoveRule
{
    public:
        SnakeMoveRuleDot(Game*);
        void apply(Snake*, SnakeMoveEvaluator*) override;

    private:
        Game* _game;
};

#endif