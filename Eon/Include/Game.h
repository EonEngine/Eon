#ifndef EON_GAME_H
#define EON_GAME_H

#include "Graphics/Renderer.h"

namespace eon {
class Game {
public:
  Game(graphics::Renderer *gameRenderer);

  void Start();

private:
  graphics::Renderer *renderer;
};
}

#endif
