#include "FPSCamera.h"

FPSCamera::FPSCamera()
    : camera(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 1.0f),
             Vec3(0.0f, 1.0f, 0.0f)) {
  TransformComponent *transform = new TransformComponent(
      Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f));
  AddComponent(transform);
}
void FPSCamera::Init() { std::cout << "FPSCamera init" << std::endl; }
void FPSCamera::Tick(float delta) {
  camera.target.x = cos(pitch) * cos(yaw);
  camera.target.y = sin(pitch);
  camera.target.z = cos(pitch) * sin(yaw);

  camera.pos = pos;

  camera.target = camera.target + camera.pos;
}
