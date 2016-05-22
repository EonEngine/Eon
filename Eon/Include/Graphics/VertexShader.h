#ifndef EON_GRAPHICS_VERTEX_SHADER_H
#define EON_GRAPHICS_VERTEX_SHADER_H

#include <string>

#include "Common.h"

namespace eon {
namespace graphics {
class VertexShader {
public:
  VertexShader(const char *source);

  inline GLuint GetID() { return id; };

private:
  GLuint id;
};
}
}

#endif
