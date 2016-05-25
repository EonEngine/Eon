#include <SDL.h>

#include "Assets/Assets.h"
#include "Eon.h"
#include "Graphics/Renderer.h"
#include "Graphics/Texture.h"

using namespace eon::assets;
using namespace eon::math;

namespace eon {
namespace graphics {

Renderer::Renderer(const char *name, int width, int height)
    : bgColor(0, 0, 0, 1), model(0), view(0), proj(0) {
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

  std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

  glViewport(0, 0, width, height);
  glEnable(GL_DEPTH_TEST);

  model = Mat4(0);
  view = Mat4::Translate(Vec3(0, 0, -3));
  proj = Mat4::Persp(M_PI / 2, width / height, 0.1, 100);
}

Renderer::~Renderer() { SDL_DestroyWindow(window); }

void Renderer::Render() {
  glClearColor(bgColor.red, bgColor.green, bgColor.blue, bgColor.alpha);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  model = Mat4::RotateX(sin((float)SDL_GetTicks() / 2000));

  GLint modelLoc = glGetUniformLocation(currentShader, "model");
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.GetElements());

  GLint viewLoc = glGetUniformLocation(currentShader, "view");
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view.GetElements());

  GLint projLoc = glGetUniformLocation(currentShader, "proj");
  glUniformMatrix4fv(projLoc, 1, GL_FALSE, proj.GetElements());

  glBindTexture(GL_TEXTURE_2D, currentTexture);

  for (int i = 0; i < meshes.size(); i++) {

    meshes[i]->Render();
  }

  glBindTexture(GL_TEXTURE_2D, 0);

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

void Renderer::SetTexture(Texture texture) { currentTexture = texture.GetID(); }
}
}
