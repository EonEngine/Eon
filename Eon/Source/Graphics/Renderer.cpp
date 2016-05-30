#include "Assets/Assets.h"
#include "Common.h"
#include "Graphics/Renderer.h"
#include "Graphics/Texture.h"
#include <stdio.h>

using namespace eon::assets;
using namespace eon::math;

namespace eon {
namespace graphics {

Renderer::Renderer(const char *name, int width, int height, bool fullScreen)
    : bgColor(0.0f, 0.0f, 0.0f, 1.0f), model(0.0f), view(0.0f), proj(0.0f) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  if (fullScreen) {
    window =
        glfwCreateWindow(width, height, name, glfwGetPrimaryMonitor(), NULL);
  } else {
    window = glfwCreateWindow(width, height, name, NULL, NULL);
  }
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

  model = Mat4(1.0f);
  view = Mat4::Translate(Vec3(0, -0.5f, 1.5f));
  proj = Mat4::Persp(M_PI / 2.0f, (float)width / (float)height, 0.1f, 100.0f);
}

Renderer::~Renderer() { glfwTerminate(); }

void Renderer::Render() {
  glClearColor(bgColor.x, bgColor.y, bgColor.z, bgColor.w);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (int i = 0; i < meshes.size(); i++) {
    materials[i]->Bind();

    glUniformMatrix4fv(materials[i]->GetModel(), 1, GL_FALSE,
                       transforms[i]->GetMatrix().GetElements());
    glUniformMatrix4fv(materials[i]->GetView(), 1, GL_FALSE,
                       view.GetElements());
    glUniformMatrix4fv(materials[i]->GetProj(), 1, GL_FALSE,
                       proj.GetElements());

    meshes[i]->Render();

    materials[i]->Unbind();
  }

  glfwSwapBuffers(window);
}

void Renderer::Add(Mesh *mesh, Material *material,
                   TransformComponent *transform) {
  meshes.push_back(mesh);
  materials.push_back(material);
  transforms.push_back(transform);
}

void Renderer::Remove(Mesh *mesh) {
  for (int i; i < meshes.size(); i++) {
    if (meshes[i] == mesh) {
      meshes.erase(meshes.begin() + i);
      materials.erase(materials.begin() + i);
      transforms.erase(transforms.begin() + i);
      break;
    }
  }
}

void Renderer::SetBackgroundColor(Vec4 color) { bgColor = color; }
}
}
