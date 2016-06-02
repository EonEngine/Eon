#include "Common.h"

#include "Entity/Entity.h"

namespace eon {
namespace entity {
void Entity::AddComponent(Component *component) {
  if (!HasComponent(component->GetType())) {
    components.push_back(component);
    return;
  }
  std::cout << "Entity Error: AddComponent(): A component of this type is "
               "already a member of this entity"
            << std::endl;
}

void Entity::RemoveComponent(Component *component) {
  for (int i = 0; i < components.size(); i++) {
    if (components[i] == component) {
      components.erase(components.begin() + i);
      break;
    }
  }
}

bool Entity::HasComponent(ComponentType type) {
  for (int i = 0; i < components.size(); i++) {
    if (components[i]->GetType() == type) {
      return true;
    }
  }
  return false;
}

int Entity::NumComponents() { return components.size(); }

Component *Entity::GetComponent(ComponentType type) {
  for (int i = 0; i < components.size(); i++) {
    if (components[i]->GetType() == type) {
      return components[i];
    }
  }
  return NULL;
}

void Entity::Init() {}
void Entity::Tick(float delta) {}
}
}
