#include <iostream>
#include <vector>

#include <Eon.h>

#include <Assets/Assets.h>
#include <Entity/Component.h>
#include <Entity/Entity.h>
#include <Graphics/Color.h>
#include <Graphics/Mesh.h>
#include <Graphics/Renderer.h>
#include <Graphics/Texture.h>
#include <Math/Mat4.h>
#include <Math/Vec2.h>
#include <Math/Vec3.h>
#include <Math/Vec4.h>

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

  Triangle triangle0(Vec3(1, 1, 0), Vec3(1, -1, 0), Vec3(-1, 1, 0), Vec2(1, 1),
                     Vec2(1, 0), Vec2(0, 1));
  Triangle triangle1(Vec3(1, -1, 0), Vec3(-1, -1, 0), Vec3(-1, 1, 0),
                     Vec2(1, 0), Vec2(0, 0), Vec2(0, 1));

  Texture texture("Tiles.jpg");
  renderer.SetTexture(texture);

  Mesh mesh0;
  mesh0.AddTriangle(triangle0);
  mesh0.AddTriangle(triangle1);
  renderer.AddMesh(&mesh0);

  VertexShader vert(LoadText("Vertex.glsl").c_str());
  FragmentShader frag(LoadText("Fragment.glsl").c_str());
  Shader shader(vert, frag);
  // TODO: Add this cleanup to Shader class
  glDeleteShader(vert.GetID());
  glDeleteShader(vert.GetID());
  renderer.SetShader(shader);

  Mat4 transform(1);
  transform.Set(0, 3, 3);
  transform.Set(1, 3, 3);
  transform.Set(2, 3, 3);

  std::cout << "Transform Matrix: " << std::endl;
  transform.Print();

  Mat4 vector(0);
  vector.Set(0, 0, 4);
  vector.Set(1, 0, 4);
  vector.Set(2, 0, 4);
  vector.Set(3, 0, 4);

  std::cout << "Vector: " << std::endl;
  vector.Print();

  std::cout << "Transform Matrix * Vector: " << std::endl;
  transform *= vector;
  transform.Print();

  int result = /*game.Start()*/ 0;

  if (result != 0) {
    std::cout << "Eon was stopped due to an internal error" << std::endl;
  } else {
    std::cout << "Eon exited normally" << std::endl;
  }
  return 0;
}
