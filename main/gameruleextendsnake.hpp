#ifndef __GAMERULEEXTENDSNAKE_HPP__
#define __GAMERULEEXTENDSNAKE_HPP__

#include "gamerule.hpp"

class GameRuleExtendSnake : public GameRule
{
    public:
        void apply(Game*) override;
};

#endif