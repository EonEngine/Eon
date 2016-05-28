include_directories(Sandbox)

add_executable(Sandbox
  Launcher.cpp
  GameMode.cpp)

target_link_libraries(Sandbox Eon ${SDL2_LIBRARY} ${SOIL_LIBRARIES} ${OPENGL_LIBRARIES})
