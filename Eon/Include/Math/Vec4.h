#ifndef EON_MATH_VEC4_H
#define EON_MATH_VEC4_H

#include "Common.h"

namespace eon {
namespace math {
class Vec4 {
public:
  Vec4();
  Vec4(float xCoord, float yCoord, float zCoord, float wCoord);

  float x, y, z, w;

  Vec4 operator+(const float &scalar);
  Vec4 operator-(const float &scalar);

  Vec4 operator+(const Vec4 &other);
  Vec4 operator-(const Vec4 &other);

  Vec4 operator*(const float &scalar);
  Vec4 operator/(const float &scalar);

  Vec4 operator*(const Vec4 &other);
  Vec4 operator/(const Vec4 &other);

  float Distance();
  float Dot(Vec4 &other);
  Vec4 Negate();
};
}
}

#endif
