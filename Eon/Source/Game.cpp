#include "Common.h"
#include "Game.h"

namespace eon {
Game::Game(Config *config)
    : renderer(config->windowTitle.c_str(), config->width, config->height,
               config->fullScreen),
      world(&renderer) {}
int Game::Start() {
  Init();
  while (!glfwWindowShouldClose(renderer.GetWindow())) {
    glfwPollEvents();

    float ms = timer.GetMs();
    timer.Reset();
    Tick(ms);

    renderer.Render();
  }
  return 0;
}

void Game::Init() {}

void Game::Tick(float delta) {}
}
