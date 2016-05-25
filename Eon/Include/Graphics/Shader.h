#ifndef EON_GRAPHICS_SHADER_H
#define EON_GRAPHICS_SHADER_H

#include "Common.h"

namespace eon {
namespace graphics {
class Shader {
public:
  Shader(const char* vertexSrc, const char* fragSrc);

  inline GLuint GetID() { return id; };

private:
  GLuint id;
};
}
}

#endif
