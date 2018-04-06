#include "game.hpp"
#include "gamerule.hpp"

void Game::update()
{
    auto ruleIterator = _rules.getIterator();
    while (ruleIterator.moveNext()) {
        auto rule = ruleIterator.getValue();
        rule->apply(this);
    }
}

int Game::getSnakeCount()
{
    return _snakes.getLength();
}

void Game::addSnake(std::shared_ptr<Snake> snake)
{
    _snakes.add(snake);
}

Iterator<Snake> Game::getSnakeIterator()
{
    return _snakes.getIterator();
}

int Game::getDotCount()
{
    return _dots.getLength();
}

void Game::addDot(std::shared_ptr<Dot> dot)
{
    _dots.add(dot);
}

Iterator<Dot> Game::getDotIterator()
{
    return _dots.getIterator();
}

void Game::addRule(std::shared_ptr<GameRule> rule)
{
    _rules.add(rule);
}