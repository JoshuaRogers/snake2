#ifndef __SNAKEFACTORY_HPP__
#define __SNAKEFACTORY_HPP__

#include "coordinate.hpp"
#include "list.hpp"

class Snake;
class SnakeMoveRule;
class SnakeFactory
{
    public:
        SnakeFactory();
        void addMoveRule(std::shared_ptr<SnakeMoveRule> rule);
        std::shared_ptr<Snake> build(Coordinate head, int length);

    private:
        List<std::shared_ptr<SnakeMoveRule>> _rules;
        int _snakeId;
};

#endif