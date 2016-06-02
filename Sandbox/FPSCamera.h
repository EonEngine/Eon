#include <Eon.h>

#include "Entity/Component.h"
#include "Entity/Components/Components.h"

class FPSCamera : public Entity {
public:
  FPSCamera();

  virtual void Init();
  virtual void Tick(float delta);

  float pitch;
  float yaw;

  Vec3 pos;

  void SetPosition(Vec3 pos);

  Camera *GetCamera() { return &camera; };

private:
  Camera camera;
};
