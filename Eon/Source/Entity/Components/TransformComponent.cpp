#include "Entity/Components/TransformComponent.h"

namespace eon {
namespace entity {
TransformComponent::TransformComponent(Vec3 position, Vec3 scaleValue)
    : pos(position), scale(scaleValue) {}

Mat4 TransformComponent::GetMatrix() {
  Mat4 ret = Mat4::Translate(pos);
  ret.Set(0, 0, scale.x);
  ret.Set(1, 1, scale.y);
  ret.Set(2, 2, scale.z);
  return ret;
}
}
}
