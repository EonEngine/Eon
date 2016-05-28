#include "Graphics/Camera.h"

namespace eon {
namespace graphics {
void Camera::LookAt(Vec3 pos) {}

Mat4 Camera::GetMatrix() {
  Mat4 ret(1.0f);
  return ret;
}
}
}
