#include <fstream>
#include <iostream>

#include "Assets.h"
#include "Common.h"

std::string assetsDir("../Assets/");

std::string LoadPosix(const char *name) {
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

std::string LoadAsset(const char *name) {
#ifdef __linux__
  return LoadPosix(name);
#elif _WIN32
  return std::string("");
#endif
  return std::string("");
}
