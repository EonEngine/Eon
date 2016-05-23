#include "Common.h"
#include "Graphics/Triangle.h"

namespace eon {
namespace graphics {
Triangle::Triangle(Vec3 point1, Vec3 point2, Vec3 point3)
    : p1(point1), p2(point2), p3(point3), p1Tex(0, 0), p2Tex(0, 0),
      p3Tex(0, 0) {}
Triangle::Triangle(Vec3 point1, Vec3 point2, Vec3 point3, Vec2 point1Tex,
                   Vec2 point2Tex, Vec2 point3Tex)
    : p1(point1), p2(point2), p3(point3), p1Tex(point1Tex), p2Tex(point2Tex),
      p3Tex(point3Tex) {}
}
}
