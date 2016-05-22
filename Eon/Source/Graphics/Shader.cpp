#include "Common.h"
#include "Graphics/Shader.h"

namespace eon {
namespace graphics {
Shader::Shader(VertexShader vertex, FragmentShader frag) {
  id = glCreateProgram();

  glAttachShader(id, vertex.GetID());
  glAttachShader(id, frag.GetID());
  glLinkProgram(id);

  GLint success;
  glGetProgramiv(id, GL_LINK_STATUS, &success);
  if (!success) {
    GLchar infoLog[512];
    glGetProgramInfoLog(id, 512, NULL, infoLog);
    std::cout << "OpenGL Shader Error: Shader Program: " << infoLog
              << std::endl;
  }
}
}
}
