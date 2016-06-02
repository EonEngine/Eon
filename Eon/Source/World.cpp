#include "Common.h"

#include "Entity/Components/Components.h"
#include "Entity/Components/RenderComponent.h"
#include "Entity/Components/TransformComponent.h"
#include "World.h"

namespace eon {
World::World(Renderer *worldRenderer) : renderer(worldRenderer) {}

void World::AddEntity(Entity *entity) {
  entities.push_back(entity);

  // Check for RenderComponent and TransformComponent
  RenderComponent *render =
      dynamic_cast<RenderComponent *>(entity->GetComponent(RENDER_COMPONENT));
  TransformComponent *transform = dynamic_cast<TransformComponent *>(
      entity->GetComponent(TRANSFORM_COMPONENT));

  if (render != NULL && transform != NULL) {
    renderer->Add(render->GetMesh(), render->GetMaterial(), transform);
  }

  entity->Init();
}
void World::RemoveEntity(Entity *entity) {
  for (int i = 0; i < entities.size(); i++) {
    if (entities[i] == entity) {
      entities.erase(entities.begin() + i);
      break;
    }
  }
}
void World::Tick(float delta) {
  for (int i = 0; i < entities.size(); i++) {
    entities[i]->Tick(delta);
  }
}
}
