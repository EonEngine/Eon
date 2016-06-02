#ifndef EON_INPUT_H
#define EON_INPUT_H

namespace eon {
class Input {
public:
  Input(GLFWwindow *inputWindow);

  void Update();

  inline float GetX() { return x; };
  inline float GetY() { return y; };

  inline double GetMouseX() { return mouseX; };
  inline double GetMouseY() { return mouseY; };
  inline double GetMouseDeltaX() { return mouseX - lastMouseX; };
  inline double GetMouseDeltaY() { return mouseY - lastMouseY; };

private:
  float x;
  float y;

  double mouseX;
  double mouseY;
  double lastMouseX;
  double lastMouseY;

  GLFWwindow *window;
};
}

#endif
