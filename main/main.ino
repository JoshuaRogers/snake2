#include <memory>
#include "beta-cube-library.h"
#include "L3D_CubePixel.h"

#include "globals.hpp"
#include "graphicsdriver.hpp"
#include "gamemode.hpp"
#include "gamemodefactory.hpp"

#define REDRAWS_PER_TICK 20

auto graphics = GraphicsDriver(Cube());
std::shared_ptr<GameMode> gameMode;

std::shared_ptr<GameMode> buildRandomGameMode()
{
  return GameModeFactory::buildVanilla(&graphics);
}

void setup() {
  Serial.begin(9600);
  while(!Serial);
  gameMode = buildRandomGameMode();
}

void loop() {
  if (!gameMode->isRunning()) {
      gameMode = buildRandomGameMode();
  }

  gameMode->tick();
  for (int i = 0; i < REDRAWS_PER_TICK; i++) {
    graphics.update(i / double(REDRAWS_PER_TICK));
  }
}
