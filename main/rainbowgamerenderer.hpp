#ifndef __RAINBOWGAMERENDERER_HPP__
#define __RAINBOWGAMERENDERER_HPP__

#include "gamerenderer.hpp"

class GraphicsDriver;
class RainbowGameRenderer : public GameRenderer
{
    public:
        RainbowGameRenderer(GraphicsDriver*);
        void render(std::shared_ptr<Game>) override;

    private:
        GraphicsDriver* _graphics;
};

#endif