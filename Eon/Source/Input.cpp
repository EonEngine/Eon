#include "Common.h"

#include "Input.h"

namespace eon {
Input::Input(GLFWwindow *inputWindow) { window = inputWindow; }

void Input::Update() {
  x = 0;
  y = 0;

  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    x++;
  }

  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    x--;
  }

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    y++;
  }

  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    y--;
  }

  lastMouseX = mouseX;
  lastMouseY = mouseY;
  glfwGetCursorPos(window, &mouseX, &mouseY);
}
}
