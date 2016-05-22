#include "Timer.h"

#ifdef __linux__
#include <time.h>
#elif _WIN32
#include "Windows.h"
#endif

namespace eon {
Timer::Timer() { Reset(); }
void Timer::Reset() {
  int t = clock();
  startTime = t;
}
int Timer::GetTicks() {
#ifdef __linux__
  int t = clock();
  return t - GetStartTime();
#elif _WIN32
  return 0;
#endif
}
float Timer::GetMs() {
  float ticks = (float)GetTicks();
  return ticks / CLOCKS_PER_SEC;
}
}
