#ifndef EON_GRAPHICS_VERTEX_H
#define EON_GRAPHICS_VERTEX_H

#include "Math/Vec2.h"
#include "Math/Vec3.h"

using namespace eon::math;

namespace eon {
namespace graphics {
class Vertex {
public:
  Vertex(Vec3 position);
  Vertex(Vec3 position, Vec2 texture);

  Vec3 pos;
  Vec2 tex;
};
}
}

#endif
