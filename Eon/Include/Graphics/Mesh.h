#ifndef EON_GRAPHICS_MESH_H
#define EON_GRAPHICS_MESH_H

#include <vector>

#include "Common.h"
#include "Graphics/Vertex.h"
#include "Math/Vec2.h"
#include "Math/Vec3.h"

namespace eon {
namespace graphics {
class Mesh {
public:
  Mesh();
  Mesh(float* verts, int numVertices, bool texCoords);

  int AddVertex(Vertex vertex);
  void RemoveVertex(int index);

  void Render();

  void GenerateVertexArray();

  void GetGL(std::vector<GLfloat> *array);

private:
  std::vector<Vertex> vertices;

  GLuint id;
};
}
}

#endif
