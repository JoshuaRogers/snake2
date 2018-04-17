#ifndef __SNAKEMOVERULEDOT_HPP__
#define __SNAKEMOVERULEDOT_HPP__

#include "snakemoverule.hpp"

class Game;
class SnakeMoveRuleDot : public SnakeMoveRule
{
    public:
        SnakeMoveRuleDot(std::weak_ptr<Game>);
        void apply(Snake*, SnakeMoveEvaluator*) override;

    private:
        std::weak_ptr<Game> _game;
};

#endif