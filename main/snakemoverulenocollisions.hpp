#ifndef __SNAKEMOVERULENOCOLLISIONS_HPP__
#define __SNAKEMOVERULENOCOLLISIONS_HPP__

#include "snakemoverule.hpp"

class Game;
class SnakeMoveRuleNoCollisions : public SnakeMoveRule
{
    public:
        SnakeMoveRuleNoCollisions(std::weak_ptr<Game>);
        void apply(Snake*, SnakeMoveEvaluator*) override;

    private:
        std::weak_ptr<Game> _game;
};

#endif