#ifndef __GAMERULESPAWNSINGLEDOT_HPP__
#define __GAMERULESPAWNSINGLEDOT_HPP__

#include "gamerule.hpp"

class Game;
class GameRuleSpawnSingleDot : public GameRule
{
    public:
        GameRuleSpawnSingleDot(int minWaitTicks, int maxWaitTicks);
        void apply(Game*) override;

    private:
        int _ticksWithoutDot;
        int _targetWaitTicks;
        const int _minWaitTicks;
        const int _maxWaitTicks;
};

#endif