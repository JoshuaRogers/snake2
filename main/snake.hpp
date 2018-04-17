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
        Snake(int snakeId, Coordinate initialCoordinate, int targetLength);
        Iterator<Coordinate> getCoordinateIterator();
        Coordinate getCoordinate(int);
        int getLength();
        int getId();

        void move();
        void extend();
        void addMoveRule(std::shared_ptr<SnakeMoveRule>);
        bool isAlive();

    private:
        SnakeDirection chooseDirection();
        bool tryMove();
        void dissolve();
        bool die();

        List<Coordinate> _coordinates;
        List<std::shared_ptr<SnakeMoveRule>> _moveRules;
        bool _isAlive;
        int _snakeId;
};

#endif