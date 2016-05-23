#ifndef EON_RENDERER_MESH_H
#define EON_RENDERER_MESH_H

#include <vector>

#include "Common.h"
#include "Graphics/Triangle.h"

namespace eon {
namespace graphics {
class Mesh {
public:
  int AddTriangle(Triangle triangle);
  void RemoveTriangle(int index);

  void Render();

  void GenerateVertexArray();

  void GetGL(std::vector<GLfloat> *array);

private:
  std::vector<Triangle> triangles;

  GLuint id;
};
}
}

#endif
