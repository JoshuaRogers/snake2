#ifndef __GAMERULEMOVESNAKE_HPP__
#define __GAMERULEMOVESNAKE_HPP__

#include "gamerule.hpp"

class GameRuleMoveSnake : public GameRule
{
    public:
        void apply(Game*) override;
};

#endif