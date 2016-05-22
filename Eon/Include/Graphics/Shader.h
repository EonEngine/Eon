#ifndef EON_GRAPHICS_SHADER_H
#define EON_GRAPHICS_SHADER_H

#include "Common.h"
#include "Graphics/FragmentShader.h"
#include "Graphics/VertexShader.h"

namespace eon {
namespace graphics {
class Shader {
public:
  Shader(VertexShader vertex, FragmentShader frag);

  inline GLuint GetID() { return id; };

private:
  GLuint id;
};
}
}

#endif
