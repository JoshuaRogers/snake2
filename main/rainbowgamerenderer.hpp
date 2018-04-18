#ifndef __RAINBOWGAMERENDERER_HPP__
#define __RAINBOWGAMERENDERER_HPP__

#include "gamerenderer.hpp"

class GraphicsDriver;
class Snake;
class RainbowGameRenderer : public GameRenderer
{
    public:
        RainbowGameRenderer(GraphicsDriver*);
        void render(std::shared_ptr<Game>) override;

    private:
        void renderSnake(std::shared_ptr<Snake> snake);
        GraphicsDriver* _graphics;
        int _tick;
};

#endif