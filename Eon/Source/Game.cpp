#include <SDL.h>
#include <stdlib.h>

#include "Eon.h"
#include "Game.h"

namespace eon {
Game::Game(graphics::Renderer *gameRenderer) { renderer = gameRenderer; }
int Game::Start() {
  SDL_Event event;
  while (true) {
    timer.Reset();
    while (SDL_PollEvent(&event)) {

      switch (event.type) {
      case SDL_QUIT: {
        return 0;
      }
      }
    }
    renderer->Render();
    std::cout << "FPS: " << 1000 / timer.GetMs() << std::endl;
  }
}
}
