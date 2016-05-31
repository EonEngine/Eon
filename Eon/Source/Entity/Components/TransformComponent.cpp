#include "Common.h"

#include "Entity/Components/TransformComponent.h"

namespace eon {
namespace entity {
TransformComponent::TransformComponent(Vec3 position, Vec3 scaleValue,
                                       Vec3 rotation)
    : pos(position), scale(scaleValue), rot(rotation) {}

Mat4 TransformComponent::GetMatrix() {
  Mat4 ret = Mat4::Translate(pos);
  ret.Set(0, 0, scale.x);
  ret.Set(1, 1, scale.y);
  ret.Set(2, 2, scale.z);
  if (rot.x != 0) {
    Mat4 rotX = Mat4::RotateX(rot.x);
    ret *= rotX;
  }
  if (rot.y != 0) {
    Mat4 rotY = Mat4::RotateY(rot.y);
    ret *= rotY;
  }
  if (rot.z != 0) {
    Mat4 rotZ = Mat4::RotateZ(rot.z);
    ret *= rotZ;
  }
  return ret;
}
}
}
