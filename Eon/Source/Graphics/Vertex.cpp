#include "Common.h"
#include "Graphics/Vertex.h"

namespace eon {
namespace graphics {
Vertex::Vertex(Vec3 position) : pos(position), tex(0, 0) {}
Vertex::Vertex(Vec3 position, Vec2 texture) : pos(position), tex(texture) {}
}
}
