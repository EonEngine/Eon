#ifndef EON_WORLD_H
#define EON_WORLD_H

#include "Common.h"
#include "Entity/Entity.h"

using namespace eon::entity;

namespace eon {
class World {
public:
  void AddEntity(Entity *entity);
  void RemoveEntity(Entity *entity);

  inline Entity *GetEntity(int i) { return entities[i]; };
  inline int GetNumEntities() { return entities.size(); };

private:
  std::vector<Entity *> entities;
};
}

#endif
