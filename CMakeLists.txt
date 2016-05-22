cmake_minimum_required(VERSION 3.5)

project(Eon)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} Eon/Include)
add_library(Eon
  Eon/Source/Assets.cpp
  Eon/Source/Entity/Entity.cpp
  Eon/Source/Entity/Component.cpp
  Eon/Source/Game.cpp
  Eon/Source/Graphics/Color.cpp
  Eon/Source/Graphics/FragmentShader.cpp
  Eon/Source/Graphics/Mesh.cpp
  Eon/Source/Graphics/Renderer.cpp
  Eon/Source/Graphics/Shader.cpp
  Eon/Source/Graphics/VertexShader.cpp
  Eon/Source/Math/Vec3.cpp)

add_executable(Sandbox Sandbox/Main.cpp)

target_link_libraries(Sandbox Eon ${SDL2_LIBRARY} ${OPENGL_LIBRARIES})
