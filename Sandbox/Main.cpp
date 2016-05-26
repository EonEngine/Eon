#include <iostream>
#include <vector>

#include <Eon.h>

#include <Assets/Assets.h>
#include <Entity/Component.h>
#include <Entity/Components/Components.h>
#include <Entity/Components/TransformComponent.h>
#include <Entity/Entity.h>
#include <Graphics/Color.h>
#include <Graphics/Mesh.h>
#include <Graphics/Renderer.h>
#include <Graphics/Texture.h>
#include <Graphics/Vertex.h>
#include <Math/Mat4.h>
#include <Math/Vec2.h>
#include <Math/Vec3.h>
#include <Math/Vec4.h>
#include <World.h>

using namespace eon;
using namespace eon::assets;
using namespace eon::entity;
using namespace eon::graphics;
using namespace eon::math;

int main() {
  std::cout << "Eon v" << EON_VERSION << " Sandbox" << std::endl;

  Renderer renderer("Eon Sandbox", 1336, 768);
  Game game(&renderer);
  renderer.SetBackgroundColor(Color(0.1, 0.1, 0.1, 1));

  Texture texture("Tiles.jpg");
  renderer.SetTexture(texture);

  float verts[] = {
      -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  -0.5f, -0.5f, 1.0f, 0.0f,
      0.5f,  0.5f,  -0.5f, 1.0f, 1.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
      -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f, -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

      -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 0.5f,  -0.5f, 0.5f,  1.0f, 0.0f,
      0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
      -0.5f, 0.5f,  0.5f,  0.0f, 1.0f, -0.5f, -0.5f, 0.5f,  0.0f, 0.0f,

      -0.5f, 0.5f,  0.5f,  1.0f, 0.0f, -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f,
      -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
      -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, -0.5f, 0.5f,  0.5f,  1.0f, 0.0f,

      0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
      0.5f,  -0.5f, -0.5f, 0.0f, 1.0f, 0.5f,  -0.5f, -0.5f, 0.0f, 1.0f,
      0.5f,  -0.5f, 0.5f,  0.0f, 0.0f, 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

      -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.5f,  -0.5f, -0.5f, 1.0f, 1.0f,
      0.5f,  -0.5f, 0.5f,  1.0f, 0.0f, 0.5f,  -0.5f, 0.5f,  1.0f, 0.0f,
      -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

      -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
      0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
      -0.5f, 0.5f,  0.5f,  0.0f, 0.0f, -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f};

  Mesh mesh(verts, 36, true);
  renderer.AddMesh(&mesh);

  Entity entity;
  TransformComponent component(Vec3(0, 0, 0), Vec3(1, 1, 1));
  entity.AddComponent(&component);
  std::cout << entity.HasComponent(TRANSFORM_COMPONENT) << std::endl;

  World world;
  world.AddEntity(&entity);

  Shader shader(LoadText("Vertex.glsl").c_str(),
                LoadText("Fragment.glsl").c_str());

  renderer.SetShader(shader);

  int result = game.Start();

  if (result != 0) {
    std::cout << "Eon was stopped due to an internal error" << std::endl;
  } else {
    std::cout << "Eon exited normally" << std::endl;
  }
  return 0;
}
