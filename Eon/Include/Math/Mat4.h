#ifndef EON_MATH_MAT4_H
#define EON_MATH_MAT4_H

namespace eon {
namespace math {
class Mat4 {
public:
  Mat4(float diagonal);

  inline float Get(uint i, uint j) { return elements[i + j * 4]; };
  inline void Set(uint i, uint j, float val) { elements[i + j * 4] = val; };

  Mat4 operator*(Mat4 &other);
  Mat4 operator*=(Mat4 &other);

  void Print();

private:
  float elements[16];
};
}
}

#endif
