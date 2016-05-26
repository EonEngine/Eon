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

private:
  std::vector<Entity *> entities;
};
}

#endif
