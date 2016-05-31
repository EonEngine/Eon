#ifndef EON_ENTITY_ENTITY_H
#define EON_ENTITY_ENTITY_H

#include <vector>

#include "Entity/Component.h"
#include "Entity/Components/Components.h"

namespace eon {
namespace entity {
class Entity {
public:
  void AddComponent(Component *component);
  void RemoveComponent(Component *component);
  bool HasComponent(ComponentType type);
  int NumComponents();

  Component *GetComponent(ComponentType type);

private:
  std::vector<Component *> components;
};
}
}

#endif
