#ifndef EON_GRAPHICS_TRIANGLE_H
#define EON_GRAPHICS_TRIANGLE_H

#include "Math/Vec3.h"

using namespace eon::math;

namespace eon {
namespace graphics {
class Triangle {
public:
  Triangle(Vec3 point1, Vec3 point2, Vec3 point3);

  inline Vec3 GetPoint1() { return p1; };
  inline Vec3 GetPoint2() { return p2; };
  inline Vec3 GetPoint3() { return p3; };

private:
  Vec3 p1, p2, p3;
};
}
}

#endif
