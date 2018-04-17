#include <memory>
#include "beta-cube-library.h"
#include "L3D_CubePixel.h"

#include "globals.hpp"
#include "game.hpp"
#include "gamerenderer.hpp"

#include "gamerulespawnsnake.hpp"
#include "gamerulespawnsingledot.hpp"
#include "gamerulemovesnake.hpp"
#include "gameruleprunedeadsnake.hpp"
#include "gameruleextendsnake.hpp"
#include "gameruleripendot.hpp"

#include "graphicsdriver.hpp"
#include "rainbowgamerenderer.hpp"

#include "coordinate.hpp"
#include "list.hpp"

#include "snakefactory.hpp"
#include "snakemoveruleinbounds.hpp"
#include "snakemoverulerandom.hpp"
#include "snakemoverulestraight.hpp"
#include "snakemoverulenocollisions.hpp"
#include "snakemoveruledot.hpp"

#define REDRAWS_PER_TICK 15

auto game = std::make_shared<Game>(Game());
auto graphics = GraphicsDriver(Cube());
auto renderer = std::make_shared<RainbowGameRenderer>(RainbowGameRenderer(&graphics));

void setup() {
  Serial.begin(9600);
  while(!Serial);

  auto snakeFactory = std::make_shared<SnakeFactory>(SnakeFactory());
  snakeFactory->addMoveRule(std::make_shared<SnakeMoveRuleInBounds>(SnakeMoveRuleInBounds(0, 0, 0, X_SIZE - 1, Y_SIZE - 1, Z_SIZE - 1)));
  snakeFactory->addMoveRule(std::make_shared<SnakeMoveRuleNoCollisions>(SnakeMoveRuleNoCollisions(std::weak_ptr<Game>(game))));
  snakeFactory->addMoveRule(std::make_shared<SnakeMoveRuleRandom>(SnakeMoveRuleRandom(6)));
  snakeFactory->addMoveRule(std::make_shared<SnakeMoveRuleStraight>(SnakeMoveRuleStraight()));
  snakeFactory->addMoveRule(std::make_shared<SnakeMoveRuleDot>(SnakeMoveRuleDot(std::weak_ptr<Game>(game))));

  game->addRule(std::make_shared<GameRuleSpawnSnake>(GameRuleSpawnSnake(snakeFactory, 6)));
  game->addRule(std::make_shared<GameRuleSpawnSingleDot>(GameRuleSpawnSingleDot(32, 64)));
  game->addRule(std::make_shared<GameRuleMoveSnake>(GameRuleMoveSnake()));
  game->addRule(std::make_shared<GameRulePruneDeadSnake>(GameRulePruneDeadSnake()));
  game->addRule(std::make_shared<GameRuleExtendSnake>(GameRuleExtendSnake()));
  game->addRule(std::make_shared<GameRuleRipenDot>(GameRuleRipenDot()));
}

void loop() {
  game->update();
  renderer->render(game);
  for (int i = 0; i < REDRAWS_PER_TICK; i++) {
    graphics.update(i / double(REDRAWS_PER_TICK));
  }
}
