#ifndef EON_GRAPHICS_TEXTURE_H
#define EON_GRAPHICS_TEXTURE_H

namespace eon {
namespace graphics {
class Texture {
public:
  Texture(const char *fileName);

  inline GLuint GetID() { return id; };

private:
  GLuint id;
};
}
}

#endif
