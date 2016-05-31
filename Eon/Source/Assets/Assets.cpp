#include <SOIL.h>
#include <fstream>
#include <iostream>

#include "Common.h"

#include "Assets/Assets.h"

namespace eon {
namespace assets {
const std::string assetsDir("../Assets/");

std::string LoadText(const char *name) {
	std::string fileName(assetsDir + name);
	std::ifstream file(fileName.c_str(), std::ios::in);

	std::string ret;

	if (file.is_open()) {
		while (file.good()) {
			ret += file.get();
		}
		ret.erase(ret.size() - 1);
		ret += (char)0;
	}
	else {
		return NULL;
	}

	file.close();

	return ret;
}

byte *LoadImage(const char *name, int *width, int *height) {
  std::string fileName(assetsDir + name);

  return SOIL_load_image(fileName.c_str(), width, height, 0, SOIL_LOAD_RGB);
}

void UnloadImage(byte *image) { SOIL_free_image_data(image); }
}
}
