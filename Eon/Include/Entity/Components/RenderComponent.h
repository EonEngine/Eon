#ifndef EON_ENTITY_COMPONENTS_RENDERCOMPONENT_H
#define EON_ENTITY_COMPONENTS_RENDERCOMPONENT_H

#include "Entity/Component.h"
#include "Entity/Components/Components.h"
#include "Graphics/Material.h"
#include "Graphics/Mesh.h"

using namespace eon::graphics;

namespace eon {
namespace entity {
class RenderComponent : public Component {
public:
  RenderComponent(Mesh *renderMesh, Material *renderMaterial);

  inline Mesh *GetMesh() { return mesh; };
  inline Material *GetMaterial() { return material; };

  virtual ComponentType GetType() { return RENDER_COMPONENT; };

private:
  Mesh *mesh;
  Material *material;
};
}
}

#endif
