#ifndef __GAMEMODE_HPP__
#define __GAMEMODE_HPP__

#include <memory>

class Game;
class GameRenderer;
class GameMode
{
    public:
        GameMode(std::shared_ptr<Game>, std::shared_ptr<GameRenderer>, int maxTicks);

        bool isRunning();
        void tick();

    private:
        std::shared_ptr<Game> _game;
        std::shared_ptr<GameRenderer> _gameRenderer;
        int _maxTicks;
        int _currentTick;
};

#endif