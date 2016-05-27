#include <iostream>
#include <vector>

#include <Eon.h>

#include <Assets/Assets.h>
#include <Config.h>
#include <Entity/Component.h>
#include <Entity/Components/Components.h>
#include <Entity/Components/RenderComponent.h>
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

#include "GameMode.h"

using namespace eon;
using namespace eon::assets;
using namespace eon::entity;
using namespace eon::graphics;
using namespace eon::math;

int main() {
  std::cout << "Eon v" << EON_VERSION << " Sandbox" << std::endl;

  // Mode
  GameMode gameMode;

  // Config
  Config config;
  config.windowTitle = "Eon Sandbox";
  config.width = 1336;
  config.height = 768;

  World world;

  Game game(&world, &gameMode, &config);

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

  Texture textureTiles("Tiles.jpg");
  Texture textureConcrete("Concrete.jpg");

  Shader shader1(LoadText("Vertex.glsl").c_str(),
                 LoadText("Fragment.glsl").c_str());
  shader1.AddTexture(textureTiles, "texture1");
  shader1.AddTexture(textureConcrete, "texture2");

  Shader shader2(LoadText("Vertex.glsl").c_str(),
                 LoadText("Fragment2.glsl").c_str());
  shader2.AddTexture(textureTiles, "cTexture");

  // Add entities
  Entity entity1;
  RenderComponent rComponent1(&mesh, &shader1);
  TransformComponent tComponent1(
      Vec3(-1.0f, 0.0f, 0.0f), Vec3(0.8f, 0.8f, 0.8f), Vec3(0.0f, 0.0f, 0.0f));
  entity1.AddComponent(&tComponent1);
  entity1.AddComponent(&rComponent1);
  world.AddEntity(&entity1);

  Entity entity2;
  RenderComponent rComponent2(&mesh, &shader2);
  TransformComponent tComponent2(Vec3(1.0f, 0.0f, 0.0f), Vec3(0.8f, 0.8f, 0.8f),
                                 Vec3(0.0f, 0.0f, 0.0f));
  entity2.AddComponent(&tComponent2);
  entity2.AddComponent(&rComponent2);
  world.AddEntity(&entity2);

  int result = game.Start();
  if (result != 0) {
    std::cout << "Eon Sandbox was stopped due to an internal error"
              << std::endl;
  } else {
    std::cout << "Eon Sandbox exited normally" << std::endl;
  }
  return 0;
}
