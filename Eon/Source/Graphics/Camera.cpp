#include "Common.h"

#include "Graphics/Camera.h"

namespace eon {
namespace graphics {
Camera::Camera(Vec3 camPos, Vec3 targetPos, Vec3 worldUpVec) {
  pos = camPos;
  target = targetPos;
  dir = Vec3::Normalize(pos - target);

  worldUp = worldUpVec;
  right = Vec3::Normalize(worldUp.Cross(dir));
  up = dir.Cross(right);
}

void Camera::Update() {
  dir = Vec3::Normalize(pos - target);
  right = Vec3::Normalize(worldUp.Cross(dir));
  up = dir.Cross(right);
}

Mat4 Camera::GetMatrix() {
  Mat4 mat(1.0f);
  Mat4 translation(1.0f);

  mat.Set(0, 0, right.x);
  mat.Set(0, 1, right.y);
  mat.Set(0, 2, right.z);

  mat.Set(1, 0, up.x);
  mat.Set(1, 1, up.y);
  mat.Set(1, 2, up.z);

  mat.Set(2, 0, -dir.x);
  mat.Set(2, 1, -dir.y);
  mat.Set(2, 2, -dir.z);

  translation.Set(0, 3, -pos.x);
  translation.Set(1, 3, -pos.y);
  translation.Set(2, 3, -pos.z);

  return mat * translation;
}
}
}
