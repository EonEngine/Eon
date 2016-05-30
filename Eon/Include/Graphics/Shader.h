#ifndef EON_GRAPHICS_SHADER_H
#define EON_GRAPHICS_SHADER_H

#include "Common.h"
#include "Graphics/Texture.h"

namespace eon {
namespace graphics {
class Shader {
public:
  Shader(const char *vertexSrc, const char *fragSrc);

  inline GLuint GetID() { return id; };

  inline GLuint GetModel() { return model; };
  inline GLuint GetView() { return view; };
  inline GLuint GetProj() { return proj; };

private:
  GLuint id;

  GLuint model;
  GLuint view;
  GLuint proj;
};
}
}

#endif
