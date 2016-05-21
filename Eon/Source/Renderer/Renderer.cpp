#include <SDL.h>

#include "Eon.hpp"
#include "Renderer/Renderer.hpp"

const char* vertexSrc = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}\0";

const char* fragSrc = "#version 330 core\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

GLuint VAO;

Renderer::Renderer(const char* name, int width, int height) : bgColor(0, 0, 0, 1)
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
      std::cout << "SDL Error: " << SDL_GetError() << std::endl;
  }

  window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

  if (window == NULL) {
      std::cout << "SDL Window Error: " << SDL_GetError() << std::endl;

  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  SDL_GLContext context = SDL_GL_CreateContext(window);

  glViewport(0, 0, width, height);

  GLuint vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexSrc, NULL);
  glCompileShader(vertexShader);

  GLint success;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

  if(!success)
  {
    GLchar infoLog[512];
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "OpenGL Shader Error: Vertex Shader: " << infoLog << std::endl;
  }

  GLuint fragShader;
  fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragShader, 1, &fragSrc, NULL);
  glCompileShader(fragShader);

  glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);

  if(!success)
  {
    GLchar infoLog[512];
    glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
    std::cout << "OpenGL Shader Error: Fragment Shader: " << infoLog << std::endl;
  }

  GLuint shaderProgram;
  shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragShader);
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if(!success) {
    GLchar infoLog[512];
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "OpenGL Shader Error: Shader Program: " << infoLog << std::endl;
  }

  glUseProgram(shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragShader);
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(window);
}

void Renderer::Render()
{
  glClearColor(bgColor.red, bgColor.green, bgColor.blue, bgColor.alpha);
  glClear(GL_COLOR_BUFFER_BIT);

  for(int i = 0; i < meshes.size(); i++)
  {
    GLfloat verts[9];
    meshes[i]->GetGL(verts, 9);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    glBindVertexArray(0);
  }

  SDL_GL_SwapWindow(window);
}

void Renderer::AddMesh(Mesh* mesh)
{
  meshes.push_back(mesh);
}

void Renderer::RemoveMesh(Mesh* mesh)
{
  for(int i; i < meshes.size(); i++)
  {
      if (meshes[i] == mesh)
      {
          meshes.erase(meshes.begin() + i);
          break;
      }
  }
}

void Renderer::SetBackgroundColor(Color color)
{
  bgColor = color;
}

Color Renderer::GetBackgroundColor()
{
  return bgColor;
}
