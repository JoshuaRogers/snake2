#ifndef __GAMERENDERER_HPP__
#define __GAMERENDERER_HPP__

#include <memory>

class Game;

class GameRenderer
{
    public:
        virtual void render(std::shared_ptr<Game>) = 0;
};

#endif