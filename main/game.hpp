#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <memory>
#include "list.hpp"
#include "iterator.hpp"

class Dot;
class GameRule;
class Snake;

class Game
{
    public:
        void update();

        int getSnakeCount();
        void addSnake(std::shared_ptr<Snake>);
        Iterator<Snake> getSnakeIterator();

        int getDotCount();
        void addDot(std::shared_ptr<Dot>);
        Iterator<Dot> getDotIterator();

        void addRule(std::shared_ptr<GameRule>);

    private:
        List<GameRule> _rules;
        List<Snake> _snakes;
        List<Dot> _dots;
};

#endif