#include <SDL.h>

#include "Assets/Assets.h"
#include "Eon.h"
#include "Graphics/Renderer.h"

using namespace eon::assets;

namespace eon {
namespace graphics {

GLuint texture;

Renderer::Renderer(const char *name, int width, int height)
    : bgColor(0, 0, 0, 1) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "SDL Error: " << SDL_GetError() << std::endl;
  }

  window =
      SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

  if (window == NULL) {
    std::cout << "SDL Window Error: " << SDL_GetError() << std::endl;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  SDL_GLContext context = SDL_GL_CreateContext(window);

  glViewport(0, 0, width, height);

  int textureW, textureH;
  byte *image = LoadImage("Concrete.jpg", &textureW, &textureH);
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureW, textureH, 0, GL_RGB,
               GL_UNSIGNED_BYTE, image);
  glGenerateMipmap(GL_TEXTURE_2D);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  glBindTexture(GL_TEXTURE_2D, 0);
}

Renderer::~Renderer() { SDL_DestroyWindow(window); }

void Renderer::Render() {
  glClearColor(bgColor.red, bgColor.green, bgColor.blue, bgColor.alpha);
  glClear(GL_COLOR_BUFFER_BIT);

  GLfloat greenValue = (sin((float)SDL_GetTicks() / 700) / 2) + 0.5;
  GLint colorLocation = glGetUniformLocation(currentShader, "vColor");
  glUniform4f(colorLocation, 0.0f, greenValue, 0.0f, 1.0f);

  glBindTexture(GL_TEXTURE_2D, texture);
  for (int i = 0; i < meshes.size(); i++) {

    meshes[i]->Render();
  }

  SDL_GL_SwapWindow(window);
}

void Renderer::AddMesh(Mesh *mesh) { meshes.push_back(mesh); }

void Renderer::RemoveMesh(Mesh *mesh) {
  for (int i; i < meshes.size(); i++) {
    if (meshes[i] == mesh) {
      meshes.erase(meshes.begin() + i);
      break;
    }
  }
}

void Renderer::SetBackgroundColor(Color color) { bgColor = color; }

Color Renderer::GetBackgroundColor() { return bgColor; }

void Renderer::SetShader(Shader shader) {
  glUseProgram(shader.GetID());
  currentShader = shader.GetID();
}
}
}
