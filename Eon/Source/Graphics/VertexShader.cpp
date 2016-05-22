#include "Common.h"
#include "Graphics/VertexShader.h"

namespace eon {
namespace graphics {
VertexShader::VertexShader(const char *source) {
  id = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(id, 1, &source, NULL);
  glCompileShader(id);

  GLint success;
  glGetShaderiv(id, GL_COMPILE_STATUS, &success);

  if (!success) {
    GLchar infoLog[512];
    glGetShaderInfoLog(id, 512, NULL, infoLog);
    std::cout << "OpenGL Shader Error: Vertex Shader: " << infoLog << std::endl;
  }
}
}
}
