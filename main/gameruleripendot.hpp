#ifndef __GAMERULERIPENDOT_HPP__
#define __GAMERULERIPENDOT_HPP__

#include "gamerule.hpp"

class GameRuleRipenDot : public GameRule
{
    public:
        void apply(Game* game) override;
};

#endif