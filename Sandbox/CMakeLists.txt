include_directories(Eon/Include Sandbox)

add_executable(Sandbox
  Launcher.cpp
  SandboxGame.cpp
  FPSCamera.cpp)

target_link_libraries(Sandbox Eon ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} glfw ${GLFW_LIBRARIES} ${SOIL_LIBRARIES})
