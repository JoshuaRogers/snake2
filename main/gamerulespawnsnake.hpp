#ifndef __GAMERULESPAWNSNAKE_HPP__
#define __GAMERULESPAWNSNAKE_HPP__

#include "gamerule.hpp"

class GameRuleSpawnSnake : public GameRule
{
    public:
        GameRuleSpawnSnake(int targetSnakeCount);
        void apply(Game*) override;

    private:
        int _targetSnakeCount;
};

#endif