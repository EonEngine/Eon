#include "Common.h"
#include "Game.h"

#ifndef __linux__
#include <unistd.h>
#endif

#ifdef _WIN32
#include <windows.h>
#endif

namespace eon {
Game::Game(Config *config)
    : renderer(config->windowTitle.c_str(), config->width, config->height,
               config->fullScreen),
      world(&renderer) {}
int Game::Start() {
  Init();

  float sync = 0.016f;

  float lastTime = glfwGetTime();

  while (!glfwWindowShouldClose(renderer.GetWindow())) {
    float curTime = glfwGetTime();
    float delta = curTime - lastTime;

    if (delta >= sync) {
      glfwPollEvents();

      lastTime = curTime;

      Tick(delta * 1000);

      renderer.Render();
    } else {
#ifndef __linux__
      usleep((sync - delta) * 1000);
#endif
#ifdef _WIN32
      Sleep(sync - delta);
#endif
    }
  }
  return 0;
}

void Game::Init() {}

void Game::Tick(float delta) {}
}
