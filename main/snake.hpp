#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include <memory>
#include "list.hpp"
#include "iterator.hpp"
#include "coordinate.hpp"
#include "snakedirection.hpp"

class SnakeMoveRule;
class Snake
{
    public:
        Snake(Coordinate initialCoordinate, int targetLength);
        Iterator<Coordinate> getCoordinateIterator();
        std::shared_ptr<Coordinate> getCoordinate(int);
        int getLength();

        void move();
        void addMoveRule(std::shared_ptr<SnakeMoveRule>);

    private:
        List<Coordinate> _coordinates;
        List<SnakeMoveRule> _moveRules;
};

#endif