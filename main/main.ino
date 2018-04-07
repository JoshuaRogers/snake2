#include <memory>
#include "beta-cube-library.h"
#include "L3D_CubePixel.h"

#include "globals.hpp"
#include "game.hpp"
#include "gamerenderer.hpp"

#include "gamerulespawnsnake.hpp"
#include "gamerulemovesnake.hpp"

#include "rainbowgamerenderer.hpp"

auto cube = Cube();
auto game = std::make_shared<Game>(Game());
auto renderer = std::make_shared<RainbowGameRenderer>(RainbowGameRenderer(&cube));

void setup() {
  Serial.begin(9600);
  while(!Serial);

  log("Initializing Cube");

  cube.begin();
  game->addRule(std::make_shared<GameRuleSpawnSnake>(GameRuleSpawnSnake(6)));
  game->addRule(std::make_shared<GameRuleMoveSnake>(GameRuleMoveSnake()));
}

void loop() {
  log("Starting update");
  game->update();

  log("Starting render");
  renderer->render(game);

  log("Starting game loop");
  delay(25);
}
