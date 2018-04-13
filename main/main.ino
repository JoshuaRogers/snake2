#include <memory>
#include "beta-cube-library.h"
#include "L3D_CubePixel.h"

#include "globals.hpp"
#include "game.hpp"
#include "gamerenderer.hpp"

#include "gamerulespawnsnake.hpp"
#include "gamerulemovesnake.hpp"
#include "gameruleprunedeadsnake.hpp"

#include "graphicsdriver.hpp"
#include "rainbowgamerenderer.hpp"

#include "coordinate.hpp"
#include "list.hpp"

auto game = std::make_shared<Game>(Game());
auto graphics = GraphicsDriver(Cube());
auto renderer = std::make_shared<RainbowGameRenderer>(RainbowGameRenderer(&graphics));

void setup() {
  Serial.begin(9600);
  while(!Serial);

  game->addRule(std::make_shared<GameRuleSpawnSnake>(GameRuleSpawnSnake(6)));
  game->addRule(std::make_shared<GameRuleMoveSnake>(GameRuleMoveSnake()));
  game->addRule(std::make_shared<GameRulePruneDeadSnake>(GameRulePruneDeadSnake()));
}

void loop() {
  game->update();
  renderer->render(game);
  for (int i = 0; i < 10; i++) {
    graphics.update(i / 10.0);
    //delay(50 / 20.0);
  }
}
