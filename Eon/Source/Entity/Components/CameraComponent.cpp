#include "Common.h"

#include "Entity/Components/CameraComponent.h"

using namespace eon::graphics;

namespace eon {
namespace entity {
CameraComponent::CameraComponent(Camera *cameraObject) : camera(cameraObject) {}
}
}
