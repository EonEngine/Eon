#include "Entity/Components/RenderComponent.h"

namespace eon {
namespace entity {
RenderComponent::RenderComponent(Mesh *mesh, Shader *shader)
    : m(mesh), s(shader) {}
}
}
