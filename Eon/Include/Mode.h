#ifndef EON_MODE_H
#define EON_MODE_H

#include "Common.h"

namespace eon {
class Mode {
public:
  virtual void Update(float delta) = 0;
};
}

#endif
