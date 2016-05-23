#ifndef EON_ASSETS_H
#define EON_ASSETS_H

#include "Common.h"

namespace eon {
namespace assets {
std::string LoadText(const char *name);
byte *LoadImage(const char *name, int *width, int *height);
}
}

#endif
