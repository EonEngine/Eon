#ifndef EON_GRAPHICS_CAMERA_H
#define EON_GRAPHICS_CAMERA_H

#include "Math/Mat4.h"
#include "Math/Vec3.h"

using namespace eon::math;

namespace eon {
namespace graphics {
class Camera {
public:
  Vec3 pos;
  Vec3 dir;

  void LookAt(Vec3 pos);

  Mat4 GetMatrix();
};
}
}

#endif
