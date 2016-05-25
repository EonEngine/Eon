#ifndef EON_GRAPHICS_COLOR_H
#define EON_GRAPHICS_COLOR_H

#include "Common.h"

namespace eon {
namespace graphics {
class Color {
public:
  Color(double r, double g, double b, double a);

  double red;
  double green;
  double blue;
  double alpha;
};
}
}

#endif
