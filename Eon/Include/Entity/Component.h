#ifndef EON_ENTITY_COMPONENT_H
#define EON_ENTITY_COMPONENT_H

#include "Common.h"
#include "Entity/Components/Components.h"

namespace eon {
namespace entity {
class Component {
public:
  virtual ComponentType GetType() { return DEFAULT; };
};
}
}

#endif
