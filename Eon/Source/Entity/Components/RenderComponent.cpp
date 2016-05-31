#include "Common.h"

#include "Entity/Components/RenderComponent.h"

namespace eon {
namespace entity {
RenderComponent::RenderComponent(Mesh *renderMesh, Material *renderMaterial)
    : mesh(renderMesh), material(renderMaterial) {}
}
}
