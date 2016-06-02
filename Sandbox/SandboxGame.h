#ifndef SANDBOX_GAME_H
#define SANDBOX_GAME_H

#include <Eon.h>
#include <Game.h>

#include "FPSCamera.h"

#include "Entity/Components/Components.h"

using namespace eon;

class SandboxGame : public Game {
public:
  SandboxGame(Config *config);

  virtual void Init();
  virtual void Tick(float delta);

private:
  Camera camera;
  FPSCamera fpsCamera;

  float yaw;
  float pitch;
};

#endif
