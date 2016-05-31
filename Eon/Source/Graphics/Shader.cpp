#include "Common.h"

#include "Graphics/Shader.h"

namespace eon {
namespace graphics {
Shader::Shader(const char *vertexSrc, const char *fragSrc) {
  GLint success;

  GLuint vertexId = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexId, 1, &vertexSrc, NULL);
  glCompileShader(vertexId);

  glGetShaderiv(vertexId, GL_COMPILE_STATUS, &success);

  if (!success) {
    GLchar infoLog[512];
    glGetShaderInfoLog(vertexId, 512, NULL, infoLog);
    std::cout << "OpenGL Shader Error: Vertex Shader: " << infoLog << std::endl;
    id = 0;
    glDeleteShader(vertexId);
    return;
  }

  GLuint fragId = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragId, 1, &fragSrc, NULL);
  glCompileShader(fragId);

  glGetShaderiv(fragId, GL_COMPILE_STATUS, &success);

  if (!success) {
    GLchar infoLog[512];
    glGetShaderInfoLog(fragId, 512, NULL, infoLog);
    std::cout << "OpenGL Shader Error: Fragment Shader: " << infoLog
              << std::endl;
    id = 0;
    glDeleteShader(vertexId);
    glDeleteShader(fragId);
    return;
  }

  id = glCreateProgram();

  glAttachShader(id, vertexId);
  glAttachShader(id, fragId);
  glLinkProgram(id);

  glGetProgramiv(id, GL_LINK_STATUS, &success);
  if (!success) {
    GLchar infoLog[512];
    glGetProgramInfoLog(id, 512, NULL, infoLog);
    std::cout << "OpenGL Shader Error: Shader Program: " << infoLog
              << std::endl;
    id = 0;
  }

  glDeleteShader(vertexId);
  glDeleteShader(fragId);

  model = glGetUniformLocation(id, "model");
  view = glGetUniformLocation(id, "view");
  proj = glGetUniformLocation(id, "proj");
}
}
}
