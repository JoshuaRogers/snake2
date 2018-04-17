#ifndef __GAMERULESPAWNSNAKE_HPP__
#define __GAMERULESPAWNSNAKE_HPP__

#include "gamerule.hpp"

class SnakeFactory;
class GameRuleSpawnSnake : public GameRule
{
    public:
        GameRuleSpawnSnake(std::shared_ptr<SnakeFactory>, int targetSnakeCount);
        void apply(Game*) override;

    private:
        std::shared_ptr<SnakeFactory> _snakeFactory;
        int _targetSnakeCount;
};

#endif