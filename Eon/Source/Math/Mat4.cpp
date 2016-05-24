#include "Common.h"
#include "Math/Mat4.h"

namespace eon {
namespace math {
Mat4::Mat4(float diagonal) {
  for (int i = 0; i < 16; i++) {
    elements[i] = 0;
  }

  Set(0, 0, diagonal);
  Set(1, 1, diagonal);
  Set(2, 2, diagonal);
  Set(3, 3, diagonal);
}

Mat4 Mat4::operator*(Mat4 &other) {
  Mat4 ret(0);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      float sum = 0;
      for (int k = 0; k < 4; k++) {
        sum += this->Get(j, k) * other.Get(k, i);
      }
      ret.Set(j, i, sum);
    }
  }
  return ret;
}

Mat4 Mat4::operator*=(Mat4 &other) { *this = *this * other; }

void Mat4::Print() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << "| " << Get(i, j) << " ";
    }
    std::cout << std::endl;
  }
}
}
}
