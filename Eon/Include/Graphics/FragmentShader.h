#ifndef EON_GRAPHICS_FRAGMENT_SHADER_H
#define EON_GRAPHICS_FRAGMENT_SHADER_H

#include <string>

#include "Common.h"

namespace eon {
namespace graphics {
class FragmentShader {
public:
  FragmentShader(const char *source);

  inline GLuint GetID() { return id; };

private:
  GLuint id;
};
}
}

#endif
