#include <SOIL.h>
#include <fstream>
#include <iostream>

#include "Assets/Assets.h"
#include "Common.h"

namespace eon {
namespace assets {
const std::string assetsDir("../Assets/");
std::string LoadTextPosix(const char *name) {
  std::string fileName(assetsDir + name);
  std::ifstream file(fileName.c_str(), std::ios::in);

  std::string ret;

  if (file.is_open()) {
    while (file.good()) {
      ret += file.get();
    }
    ret.erase(ret.size() - 1);
    ret += (char)0;
  } else {
    return NULL;
  }

  file.close();

  return ret;
}

std::string LoadText(const char *name) {
#ifdef __linux__
  return LoadTextPosix(name);
#elif _WIN32
  return std::string("");
#endif
  return std::string("");
}

byte *LoadImage(const char *name, int *width, int *height) {
  std::string fileName(assetsDir + name);

  return SOIL_load_image(fileName.c_str(), width, height, 0, SOIL_LOAD_RGB);
}

void UnloadImage(byte *image) { SOIL_free_image_data(image); }
}
}
