#ifndef EON_WORLD_H
#define EON_WORLD_H

#include "Entity/Entity.h"
#include "Graphics/Renderer.h"

using namespace eon::entity;
using namespace eon::graphics;

namespace eon {
class World {
public:
  World(Renderer *worldRenderer);

  void AddEntity(Entity *entity);
  void RemoveEntity(Entity *entity);

  inline Entity *GetEntity(int i) { return entities[i]; };
  inline int GetNumEntities() { return entities.size(); };

  void Tick(float delta);

private:
  Renderer *renderer;

  std::vector<Entity *> entities;
};
}

#endif
