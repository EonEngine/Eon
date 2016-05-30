#ifndef EON_GAME_H
#define EON_GAME_H

#include "Common.h"
#include "Config.h"
#include "Graphics/Renderer.h"
#include "World.h"

using namespace eon::graphics;

namespace eon {
class Game {
public:
  Game(Config *config);

  inline World *GetWorld() { return &world; };
  inline Renderer *GetRenderer() { return &renderer; };

  int Start();

  virtual void Init();
  virtual void Tick(float delta);

protected:
  Renderer renderer;
  World world;
};
}

#endif
