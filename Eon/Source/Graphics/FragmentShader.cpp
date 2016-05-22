#include "Common.h"
#include "Graphics/FragmentShader.h"

namespace eon {
namespace graphics {
FragmentShader::FragmentShader(const char *source) {
  id = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(id, 1, &source, NULL);
  glCompileShader(id);

  GLint success;
  glGetShaderiv(id, GL_COMPILE_STATUS, &success);

  if (!success) {
    GLchar infoLog[512];
    glGetShaderInfoLog(id, 512, NULL, infoLog);
    std::cout << "OpenGL Shader Error: Fragment Shader: " << infoLog
              << std::endl;
  }
}
}
}
