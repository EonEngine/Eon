#ifndef EON_GAME_H
#define EON_GAME_H

#include "Common.h"
#include "Graphics/Renderer.h"
#include "Timer.h"

namespace eon {
class Game {
public:
  Game(graphics::Renderer *gameRenderer);

  int Start();

private:
  Timer timer;
  graphics::Renderer *renderer;
};
}

#endif
