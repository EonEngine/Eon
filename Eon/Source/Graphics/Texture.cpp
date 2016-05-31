#include "Common.h"

#include "Assets/Assets.h"
#include "Graphics/Texture.h"

using namespace eon::assets;

namespace eon {
namespace graphics {
Texture::Texture(const char *fileName) {
  int textureW, textureH;
  byte *image = LoadImage(fileName, &textureW, &textureH);
  glGenTextures(1, &id);
  glBindTexture(GL_TEXTURE_2D, id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureW, textureH, 0, GL_RGB,
               GL_UNSIGNED_BYTE, image);
  glGenerateMipmap(GL_TEXTURE_2D);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  glBindTexture(GL_TEXTURE_2D, 0);
  UnloadImage(image);
}
}
}
