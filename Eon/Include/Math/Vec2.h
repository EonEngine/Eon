#ifndef EON_MATH_VEC2_H
#define EON_MATH_VEC2_H

namespace eon {
namespace math {
class Vec2 {
public:
  Vec2();
  Vec2(float xCoord, float yCoord);

  float x, y;

  Vec2 operator+(const float &scalar);
  Vec2 operator-(const float &scalar);

  Vec2 operator+(const Vec2 &other);
  Vec2 operator-(const Vec2 &other);

  Vec2 operator*(const float &scalar);
  Vec2 operator/(const float &scalar);

  Vec2 operator*(const Vec2 &other);
  Vec2 operator/(const Vec2 &other);

  float Distance();
  float Dot(Vec2 &other);
  Vec2 Negate();
};
}
}

#endif
