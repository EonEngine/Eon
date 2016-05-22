#ifndef EON_RENDERER_MESH_H
#define EON_RENDERER_MESH_H

#include <vector>

#include "Common.h"
#include "Math/Vec3.h"

namespace eon {
namespace graphics {
using namespace math;
class Mesh {
public:
  int AddVertex(Vec3 pos);
  void RemoveVertex(int index);

  void GetGL(GLfloat array[], int size);

private:
  std::vector<Vec3> vertices;
};
}
}

#endif
