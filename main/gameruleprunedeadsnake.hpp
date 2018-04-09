#ifndef __GAMERULEPRUNEDEADSNAKE_HPP__
#define __GAMERULEPRUNEDEADSNAKE_HPP__

#include "gamerule.hpp"

class GameRulePruneDeadSnake : public GameRule
{
    public:
        void apply(Game*) override;
};

#endif