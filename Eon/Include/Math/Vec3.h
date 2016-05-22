#ifndef EON_MATH_VEC3_H
#define EON_MATH_VEC3_H

#include "Common.h"

namespace eon {
namespace math {
class Vec3 {
public:
  Vec3(float xCoord, float yCoord, float zCoord);

  float GetX();
  float GetY();
  float GetZ();

  float Distance();

private:
  float x, y, z;
};
}
}

#endif
