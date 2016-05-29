#ifndef EON_GRAPHICS_RENDERER_H
#define EON_GRAPHICS_RENDERER_H

#include <vector>

#include "Common.h"
#include "Entity/Components/Components.h"
#include "Entity/Components/RenderComponent.h"
#include "Entity/Components/TransformComponent.h"
#include "Graphics/Color.h"
#include "Graphics/Mesh.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Math/Mat4.h"
#include "World.h"

namespace eon {
namespace graphics {
class Renderer {
public:
  Renderer(World *renderWorld, const char *name, int width, int height);
  ~Renderer();

  void Render();

  void SetBackgroundColor(Color color);
  Color GetBackgroundColor();

  inline GLFWwindow *GetWindow() { return window; };

  void SetShader(Shader shader);

  void SetTexture(Texture texture);

private:
  World *world;

  GLFWwindow *window;

  Color bgColor;

  std::vector<Mesh *> meshes;

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
