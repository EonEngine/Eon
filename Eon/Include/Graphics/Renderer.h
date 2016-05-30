#ifndef EON_GRAPHICS_RENDERER_H
#define EON_GRAPHICS_RENDERER_H

#include <vector>

#include "Common.h"
#include "Entity/Components/TransformComponent.h"
#include "Graphics/Material.h"
#include "Graphics/Mesh.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Math/Mat4.h"
#include "Math/Vec4.h"

using namespace eon::entity;

namespace eon {
namespace graphics {
class Renderer {
public:
  Renderer(const char *name, int width, int height, bool fullScreen);
  ~Renderer();

  void Render();

  void SetBackgroundColor(Vec4 color);

  inline GLFWwindow *GetWindow() { return window; };

  void Add(Mesh *mesh, Material *material, TransformComponent *transform);
  void Remove(Mesh *mesh);

private:
  GLFWwindow *window;

  Vec4 bgColor;

  std::vector<Mesh *> meshes;
  std::vector<Material *> materials;
  std::vector<TransformComponent *> transforms;

  GLuint currentShader;

  GLuint currentTexture;

  GLuint modelLoc;
  GLuint viewLoc;
  GLint projLoc;

  Mat4 model;
  Mat4 view;
  Mat4 proj;
};
}
}

#endif
