#ifndef __RAINBOWGAMERENDERER_HPP__
#define __RAINBOWGAMERENDERER_HPP__

#include "gamerenderer.hpp"

class Cube;
class RainbowGameRenderer : public GameRenderer
{
    public:
        RainbowGameRenderer(Cube*);
        void render(std::shared_ptr<Game>) override;

    private:
        Cube* _cube;
};

#endif