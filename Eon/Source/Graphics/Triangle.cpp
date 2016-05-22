#include "Common.h"
#include "Graphics/Triangle.h"

namespace eon {
namespace graphics {
Triangle::Triangle(Vec3 point1, Vec3 point2, Vec3 point3)
    : p1(point1), p2(point2), p3(point3) {}
}
}
