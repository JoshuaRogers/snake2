#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <memory>
#include "list.hpp"
#include "iterator.hpp"

/*3D Single Player
2D Planes. Or, as Jenna pointed out, "Snakes on a plane."
3D Multiplayer
3D Ghost Multiplayer
Mirrored
Concentric Spheres
Matrix
Split Rather Than Extend*/

/*
Snake knows the grid it can move inside of.

World Rule: Snake must move every turn
World Rule: Snake cannot intersect itself
World Rule: Snake grows if it eats a dot
World Rule: Snake splits if it eats a dot
World Rule: Snake cannot intersect other snakes
World Rule: A dot spawns after a period of time
World Rule: A dot spawns for each snake
World Rule: A dot despawns if a snake intersects it
World Rule: A snake spawns if there are fewer than three snakes
*/

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