#ifndef SANDBOX_GAME_H
#define SANDBOX_GAME_H

#include <Eon.h>
#include <Game.h>

using namespace eon;

class SandboxGame : public Game {
public:
  SandboxGame(Config *config);

  virtual void Init();
  virtual void Tick(float delta);
};

#endif
