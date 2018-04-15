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
        void removeSnake(std::shared_ptr<Snake>);
        Iterator<std::shared_ptr<Snake>> getSnakeIterator();

        int getDotCount();
        void addDot(std::shared_ptr<Dot>);
        void removeDot(std::shared_ptr<Dot>);
        Iterator<std::shared_ptr<Dot>> getDotIterator();

        void addRule(std::shared_ptr<GameRule>);

    private:
        List<std::shared_ptr<GameRule>> _rules;
        List<std::shared_ptr<Snake>> _snakes;
        List<std::shared_ptr<Dot>> _dots;
};

#endif