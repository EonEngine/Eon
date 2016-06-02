#include "Common.h"

#include "Game.h"

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#endif

namespace eon {
Game::Game(Config *config)
    : renderer(config->windowTitle.c_str(), config->width, config->height,
               config->fullScreen),
      world(&renderer), input(renderer.GetWindow()) {}
int Game::Start() {
  Init();

  float lastTime = glfwGetTime();

  while (!glfwWindowShouldClose(renderer.GetWindow())) {
    float curTime = glfwGetTime();
    float delta = curTime - lastTime;
    glfwPollEvents();
    input.Update();

    lastTime = curTime;

    Tick(delta * 1000);
    world.Tick(delta * 1000);

    renderer.Render();
  }
  return 0;
}

void Game::Init() {}

void Game::Tick(float delta) {}
}
