#include "Graphics/Camera.h"

namespace eon {
namespace graphics {
Camera::Camera(Vec3 position, Vec3 target, Vec3 upVec) {
  pos = position;
  dir = pos - target;
  dir = dir.Normalize();
  right = up.Cross(dir);
  right = right.Normalize();
  up = dir.Cross(right);
}

Mat4 Camera::GetMatrix() {
  Mat4 mat1(1.0f);
  Mat4 mat2(1.0f);

  mat1.Set(0, 0, right.x);
  mat1.Set(0, 1, right.y);
  mat1.Set(0, 2, right.z);
  mat1.Set(1, 0, up.x);
  mat1.Set(1, 1, up.y);
  mat1.Set(1, 2, up.z);
  mat1.Set(2, 0, dir.x);
  mat1.Set(2, 1, dir.y);
  mat1.Set(2, 2, dir.z);

  mat1.Print();

  mat2.Set(0, 3, -pos.x);
  mat2.Set(1, 3, -pos.y);
  mat2.Set(2, 3, -pos.z);

  mat2.Print();

  return mat1 * mat2;
}
}
}
