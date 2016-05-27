#include <SDL.h>

#include "Eon.h"
#include "Game.h"

namespace eon {
Game::Game(World *world, Mode *gameMode, Config *config)
    : renderer(world, config->windowTitle.c_str(), config->width,
               config->height),
      mode(gameMode) {}
int Game::Start() {
  SDL_Event event;
  while (true) {
    while (SDL_PollEvent(&event)) {

      switch (event.type) {
      case SDL_QUIT: {
        return 0;
      }
      case SDL_KEYDOWN: {
        return 0;
      }
      }
    }

    float ms = timer.GetMs();
    timer.Reset();
    mode->Update(ms);

    renderer.Render();
  }
}
}
