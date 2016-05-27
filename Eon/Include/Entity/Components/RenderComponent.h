#ifndef EON_ENTITY_COMPONENTS_RENDERCOMPONENT_H
#define EON_ENTITY_COMPONENTS_RENDERCOMPONENT_H

#include "Common.h"
#include "Entity/Component.h"
#include "Entity/Components/Components.h"
#include "Graphics/Mesh.h"
#include "Graphics/Shader.h"

using namespace eon::graphics;

namespace eon {
namespace entity {
class RenderComponent : public Component {
public:
  RenderComponent(Mesh *mesh, Shader *shader);

  inline Mesh *GetMesh() { return m; };
  inline Shader *GetShader() { return s; };

  virtual ComponentType GetType() { return RENDER_COMPONENT; };

private:
  Mesh *m;
  Shader *s;
};
}
}

#endif
