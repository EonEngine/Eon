#ifndef EON_MATH_VEC3_H
#define EON_MATH_VEC3_H

#include "Common.h"

namespace eon {
namespace math {
class Vec3 {
public:
  Vec3();
  Vec3(float xCoord, float yCoord, float zCoord);

  float x, y, z;

  Vec3 operator+(const float &scalar);
  Vec3 operator-(const float &scalar);

  Vec3 operator+(const Vec3 &other);
  Vec3 operator-(const Vec3 &other);

  Vec3 operator*(const float &scalar);
  Vec3 operator/(const float &scalar);

  Vec3 operator*(const Vec3 &other);
  Vec3 operator/(const Vec3 &other);

  float Distance();
  float Dot(Vec3 &other);
  Vec3 Cross(Vec3 &other);
  Vec3 Negate();
  Vec3 Normalize();
};
}
}

#endif
