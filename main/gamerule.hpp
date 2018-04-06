#ifndef __GAMERULE_HPP__
#define __GAMERULE_HPP__

class Game;
class GameRule
{
    public:
        virtual void apply(Game*) = 0;
};

#endif