#include "Common.h"
#include "Eon.h"
#include "Game.h"

namespace eon {
Game::Game(World *world, Mode *gameMode, Config *config)
    : renderer(world, config->windowTitle.c_str(), config->width,
               config->height),
      mode(gameMode) {}
int Game::Start() {
  while (!glfwWindowShouldClose(renderer.GetWindow())) {
    glfwPollEvents();

    float ms = timer.GetMs();
    timer.Reset();
    mode->Update(ms);

    renderer.Render();
  }
  return 0;
}
}
