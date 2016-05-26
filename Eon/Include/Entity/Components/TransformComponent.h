#ifndef EON_ENTITY_COMPONENTS_TRANSFORMCOMPONENT_H
#define EON_ENTITY_COMPONENTS_TRANSFORMCOMPONENT_H

#include "Entity/Component.h"
#include "Entity/Components/Components.h"
#include "Math/Mat4.h"

using namespace eon::math;

namespace eon {
namespace entity {
class TransformComponent : public Component {
public:
  TransformComponent(Vec3 position, Vec3 scaleValue);

  Mat4 GetMatrix();

  Vec3 pos;
  Vec3 scale;

  virtual ComponentType GetType() { return TRANSFORM_COMPONENT; };
};
}
}

#endif
