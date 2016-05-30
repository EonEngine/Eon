include_directories(Eon/Include Sandbox)

add_executable(Sandbox
  Launcher.cpp
  SandboxGame.cpp)

target_link_libraries(Sandbox Eon ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} ${SOIL_LIBRARIES})
