#include <math.h>

#include "Math/Vec3.h"

namespace eon {
namespace math {
Vec3::Vec3(float xCoord, float yCoord, float zCoord) {
  x = xCoord;
  y = yCoord;
  z = zCoord;
}

float Vec3::Distance() { return sqrt(x * x + y * y + z * z); }

float Vec3::GetX() { return x; }

float Vec3::GetY() { return y; }

float Vec3::GetZ() { return z; }
}
}
