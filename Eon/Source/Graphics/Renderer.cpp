#include <SDL.h>

#include "Assets/Assets.h"
#include "Eon.h"
#include "Graphics/Renderer.h"
#include "Graphics/Texture.h"

using namespace eon::assets;
using namespace eon::math;

namespace eon {
namespace graphics {

Renderer::Renderer(World *renderWorld, const char *name, int width, int height)
    : world(renderWorld), bgColor(0, 0, 0, 1), model(0), view(0), proj(0) {
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

  model = Mat4(1);
  view = Mat4::Translate(Vec3(0, 0, 2));
  proj = Mat4::Persp(M_PI / 2, (float)width / (float)height, 0.1, 100);
}

Renderer::~Renderer() { SDL_DestroyWindow(window); }

void Renderer::Render() {
  glClearColor(bgColor.red, bgColor.green, bgColor.blue, bgColor.alpha);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view.GetElements());
  glUniformMatrix4fv(projLoc, 1, GL_FALSE, proj.GetElements());

  glBindTexture(GL_TEXTURE_2D, currentTexture);

  for (int i = 0; i < world->GetNumEntities(); i++) {
    RenderComponent *render = dynamic_cast<RenderComponent *>(
        world->GetEntity(i)->GetComponent(RENDER_COMPONENT));
    TransformComponent *transform = dynamic_cast<TransformComponent *>(
        world->GetEntity(i)->GetComponent(TRANSFORM_COMPONENT));

    if (render != NULL && transform != NULL) {
      glUniformMatrix4fv(modelLoc, 1, GL_FALSE,
                         transform->GetMatrix().GetElements());

      std::cout << render->GetShader()->GetID();
      glUseProgram(render->GetShader()->GetID());
      render->GetMesh()->Render();
    }
  }

  glBindTexture(GL_TEXTURE_2D, 0);

  SDL_GL_SwapWindow(window);
}

void Renderer::SetBackgroundColor(Color color) { bgColor = color; }

Color Renderer::GetBackgroundColor() { return bgColor; }

void Renderer::SetShader(Shader shader) {
  glUseProgram(shader.GetID());
  currentShader = shader.GetID();

  modelLoc = glGetUniformLocation(currentShader, "model");
  viewLoc = glGetUniformLocation(currentShader, "view");
  projLoc = glGetUniformLocation(currentShader, "proj");
}

void Renderer::SetTexture(Texture texture) { currentTexture = texture.GetID(); }
}
}
