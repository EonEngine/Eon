#include <SDL.h>

#include "Eon.h"
#include "Game.h"

namespace eon {
Game::Game(graphics::Renderer *gameRenderer) { renderer = gameRenderer; }
void Game::Start() {
  SDL_Event event;
  while (SDL_WaitEvent(&event) >= 0) {
    switch (event.type) {
    case SDL_QUIT: {
      return;
    }

    case SDL_KEYDOWN: {
      // Q key = Quit
      if (event.key.keysym.sym) {
        return;
      }
    }
    }

    renderer->Render();
  }
}
}
