#ifndef EON_TIMER_H
#define EON_TIMER_H

#include "Common.h"

namespace eon {
class Timer {
public:
  Timer();

  inline int GetStartTime() { return startTime; }
  int GetTicks();
  float GetMs();

  void Reset();

private:
  int startTime;
};
}

#endif
