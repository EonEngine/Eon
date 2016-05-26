#include "World.h"

namespace eon {
void World::AddEntity(Entity *entity) { entities.push_back(entity); }
void World::RemoveEntity(Entity *entity) {
  for (int i; i < entities.size(); i++) {
    if (entities[i] == entity) {
      entities.erase(entities.begin() + i);
      break;
    }
  }
}
}
