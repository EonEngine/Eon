#ifndef EON_GRAPHICS_TRIANGLE_H
#define EON_GRAPHICS_TRIANGLE_H

#include "Math/Vec2.h"
#include "Math/Vec3.h"

using namespace eon::math;

namespace eon {
namespace graphics {
class Triangle {
public:
  Triangle(Vec3 point1, Vec3 point2, Vec3 point3);
  Triangle(Vec3 point1, Vec3 point2, Vec3 point3, Vec2 point1Tex,
           Vec2 point2Tex, Vec2 point3Tex);

  Vec2 p1Tex, p2Tex, p3Tex;
  Vec3 p1, p2, p3;
};
}
}

#endif
