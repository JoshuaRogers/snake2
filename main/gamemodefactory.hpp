#ifndef __GAMEMODEFACTORY_HPP__
#define __GAMEMODEFACTORY_HPP__

#include <memory>

class GameMode;
class GraphicsDriver;
class GameModeFactory
{
    public:
        static std::shared_ptr<GameMode> buildVanilla(GraphicsDriver*);
};

#endif