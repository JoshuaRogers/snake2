#include "game.hpp"
#include "gamerule.hpp"

void Game::update()
{
    auto ruleIterator = _rules.getIterator();
    while (ruleIterator.moveNext()) {
        auto rule = ruleIterator.getValue().get();
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

void Game::removeSnake(std::shared_ptr<Snake> snake)
{
    int index = -1;
    auto snakes = _snakes.getIterator();
    while(snakes.moveNext()) {
        index++;
        if (snake == snakes.getValue()) {
            break;
        }
    }

    if (index != -1) {
        _snakes.remove(index);
    }
}

Iterator<std::shared_ptr<Snake>> Game::getSnakeIterator()
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

void Game::removeDot(std::shared_ptr<Dot> dot)
{
    int index = -1;
    auto dots = _dots.getIterator();
    while(dots.moveNext()) {
        index++;
        if (dot == dots.getValue()) {
            break;
        }
    }

    if (index != -1) {
        _dots.remove(index);
    }
}

Iterator<std::shared_ptr<Dot>> Game::getDotIterator()
{
    return _dots.getIterator();
}

void Game::addRule(std::shared_ptr<GameRule> rule)
{
    _rules.add(rule);
}