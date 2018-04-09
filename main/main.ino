#include <memory>
#include "beta-cube-library.h"
#include "L3D_CubePixel.h"

#include "globals.hpp"
#include "game.hpp"
#include "gamerenderer.hpp"

#include "gamerulespawnsnake.hpp"
#include "gamerulemovesnake.hpp"
#include "gameruleprunedeadsnake.hpp"

#include "rainbowgamerenderer.hpp"

#include "coordinate.hpp"
#include "list.hpp"

auto cube = Cube();
auto game = std::make_shared<Game>(Game());
auto renderer = std::make_shared<RainbowGameRenderer>(RainbowGameRenderer(&cube));

void setup() {
  Serial.begin(9600);
  while(!Serial);

  cube.begin();
  game->addRule(std::make_shared<GameRuleSpawnSnake>(GameRuleSpawnSnake(5)));
  game->addRule(std::make_shared<GameRuleMoveSnake>(GameRuleMoveSnake()));
  game->addRule(std::make_shared<GameRulePruneDeadSnake>(GameRulePruneDeadSnake()));
}

void loop() {
  game->update();
  renderer->render(game);
  delay(25);
}
