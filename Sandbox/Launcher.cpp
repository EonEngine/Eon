#include <iostream>
#include <vector>

#include <Eon.h>

#include "SandboxGame.h"

using namespace eon;
using namespace eon::assets;
using namespace eon::entity;
using namespace eon::graphics;
using namespace eon::math;

int main() {
  std::cout << "Eon v" << EON_VERSION << " Sandbox" << std::endl;

  // Config
  Config config;
  config.windowTitle = "Eon Sandbox";
  config.width = 640;
  config.height = 480;
  config.fullScreen = false;

  SandboxGame game(&config);

  int result = game.Start();
  if (result != 0) {
    std::cout << "Eon Sandbox was stopped due to an internal error"
              << std::endl;
  } else {
    std::cout << "Eon Sandbox exited normally" << std::endl;
  }
  return 0;
}
