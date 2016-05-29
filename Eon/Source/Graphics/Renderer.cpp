#include "Assets/Assets.h"
#include "Common.h"
#include "Eon.h"
#include "Graphics/Renderer.h"
#include "Graphics/Texture.h"
#include <stdio.h>

using namespace eon::assets;
using namespace eon::math;

namespace eon {
namespace graphics {

Renderer::Renderer(World *renderWorld, const char *name, int width, int height)
    : world(renderWorld), bgColor(0, 0, 0, 1), model(0), view(0), proj(0) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  window = glfwCreateWindow(width, height, name, NULL, NULL);
  if (window == NULL) {
    std::cout << "GLFW Error: Unable to create window" << std::endl;
    glfwTerminate();
  }
  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cout << "GLEW Error: Unable to initialize GLEW" << std::endl;
  }

  std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

  glViewport(0, 0, width, height);
  glEnable(GL_DEPTH_TEST);

  model = Mat4(1);
  view = Mat4::Translate(Vec3(0, 0, 2));
  proj = Mat4::Persp(M_PI / 2, (float)width / (float)height, 0.1, 100);
}

Renderer::~Renderer() { glfwTerminate(); }

void Renderer::Render() {
  glClearColor(bgColor.red, bgColor.green, bgColor.blue, bgColor.alpha);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (int i = 0; i < world->GetNumEntities(); i++) {
    RenderComponent *render = dynamic_cast<RenderComponent *>(
        world->GetEntity(i)->GetComponent(RENDER_COMPONENT));
    TransformComponent *transform = dynamic_cast<TransformComponent *>(
        world->GetEntity(i)->GetComponent(TRANSFORM_COMPONENT));

    if (render != NULL && transform != NULL) {
      render->GetShader()->Render();

      glUniformMatrix4fv(render->GetShader()->GetModel(), 1, GL_FALSE,
                         transform->GetMatrix().GetElements());
      glUniformMatrix4fv(render->GetShader()->GetView(), 1, GL_FALSE,
                         view.GetElements());
      glUniformMatrix4fv(render->GetShader()->GetProj(), 1, GL_FALSE,
                         proj.GetElements());

      render->GetMesh()->Render();
    }
  }

  glfwSwapBuffers(window);
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
