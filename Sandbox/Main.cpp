#include <iostream>
#include <vector>

#include <Eon.h>

#include <Assets.h>
#include <Entity/Component.h>
#include <Entity/Entity.h>
#include <Graphics/Color.h>
#include <Graphics/Mesh.h>
#include <Graphics/Renderer.h>
#include <Math/Vec3.h>

using namespace eon;
using namespace eon::entity;
using namespace eon::graphics;
using namespace eon::math;

int main() {
  std::cout << "Eon v" << EON_VERSION << " Sandbox" << std::endl;

  Renderer renderer("Eon Sandbox", 1336, 768);
  Game game(&renderer);
  renderer.SetBackgroundColor(Color(0.1, 0.1, 0.1, 1));

  Triangle triangle0(Vec3(0.5, 0.5, 0), Vec3(0.5, -0.5, 0), Vec3(-0.5, 0.5, 0));
  Triangle triangle1(Vec3(0.5, -0.5, 0), Vec3(-0.5, -0.5, 0),
                     Vec3(-0.5, 0.5, 0));

  Mesh mesh0;
  mesh0.AddTriangle(triangle0);
  mesh0.AddTriangle(triangle1);

  renderer.AddMesh(&mesh0);

  VertexShader vert(LoadAsset("Vertex.glsl").c_str());
  FragmentShader frag(LoadAsset("Fragment.glsl").c_str());
  Shader shader(vert, frag);

  glDeleteShader(vert.GetID());
  glDeleteShader(vert.GetID());

  renderer.SetShader(shader);

  int result = game.Start();

  if (result != 0) {
    std::cout << "Eon was stopped due to an internal error";
  } else {
    std::cout << "Eon exited normally";
  }
  return 0;
}
