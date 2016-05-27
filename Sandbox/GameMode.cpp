#include "GameMode.h"

void GameMode::Update(float delta) {
  std::cout << "FPS: " << 1000 / delta << std::endl;
}
