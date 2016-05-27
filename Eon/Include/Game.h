#ifndef EON_GAME_H
#define EON_GAME_H

#include "Common.h"
#include "Config.h"
#include "Graphics/Renderer.h"
#include "Mode.h"
#include "Timer.h"

using namespace eon::graphics;

namespace eon {
class Game {
public:
  Game(World *world, Mode *gameMode, Config *config);

  inline Renderer *GetRenderer() { return &renderer; };

  int Start();

private:
  Timer timer;
  Renderer renderer;
  Mode *mode;
};
}

#endif
