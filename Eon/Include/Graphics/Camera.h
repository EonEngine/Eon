#ifndef EON_GRAPHICS_CAMERA_H
#define EON_GRAPHICS_CAMERA_H

#include "Math/Mat4.h"
#include "Math/Vec3.h"

using namespace eon::math;

namespace eon {
namespace graphics {
class Camera {
public:
  Camera(Vec3 camPos, Vec3 targetPos, Vec3 worldUpVec);

  Vec3 right;
  Vec3 target;
  Vec3 up;
  Vec3 worldUp;
  Vec3 pos;
  Vec3 dir;

  void Update();

  Mat4 GetMatrix();
};
}
}

#endif
