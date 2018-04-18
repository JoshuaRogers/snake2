#include "gamemode.hpp"
#include "game.hpp"
#include "gamerenderer.hpp"


GameMode::GameMode(std::shared_ptr<Game> game, std::shared_ptr<GameRenderer> gameRenderer, int maxTicks) : _game(game),
                                                                                                           _gameRenderer(gameRenderer),
                                                                                                           _maxTicks(maxTicks),
                                                                                                           _currentTick(0) { }

bool GameMode::isRunning()
{
    return _currentTick < _maxTicks;
}

void GameMode::tick()
{
    _game->update();
    _gameRenderer->render(_game);
    _currentTick++;
}
