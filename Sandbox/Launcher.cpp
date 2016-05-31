#include <iostream>
#include <vector>

#include <Eon.h>

#include "SandboxGame.h"

using namespace eon;
using namespace eon::assets;
using namespace eon::entity;
using namespace eon::graphics;
using namespace eon::math;

int main() {
  std::cout << "Eon v" << EON_VERSION << " Sandbox" << std::endl;

  // Config
  Config config;
  config.windowTitle = "Eon Sandbox";
  config.width = 1336;
  config.height = 768;
  config.fullScreen = false;

  //SandboxGame game(&config);
  
	  GLFWwindow* window;

	  /* Initialize the library */
	  if (!glfwInit())
		  return -1;

	  /* Create a windowed mode window and its OpenGL context */
	  window = glfwCreateWindow(400, 400, "Hello World", NULL, NULL);
	  if (!window)
	  {
		  glfwTerminate();
		  return -2;
	  }

	  /* Make the window's context current */
	  glfwMakeContextCurrent(window);

	  /* Loop until the user closes the window */
	  while (!glfwWindowShouldClose(window))
	  {
		  /* Render here */

		  /* Swap front and back buffers */
		  glfwSwapBuffers(window);

		  /* Poll for and process events */
		  glfwPollEvents();
	  }

	  glfwTerminate();
	  return 0;

  int result = 0;
  if (result != 0) {
    std::cout << "Eon Sandbox was stopped due to an internal error"
              << std::endl;
  } else {
    std::cout << "Eon Sandbox exited normally" << std::endl;
  }
  return 0;
}
