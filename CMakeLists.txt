cmake_minimum_required(VERSION 3.5)

project(Eon)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake")
find_package(SDL2 REQUIRED)
find_package(SOIL REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SOIL_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} Eon/Include)
add_library(Eon
  Eon/Source/Assets/Assets.cpp
  Eon/Source/Entity/Entity.cpp
  Eon/Source/Entity/Component.cpp
  Eon/Source/Entity/Components/MeshComponent.cpp
  Eon/Source/Entity/Components/TransformComponent.cpp
  Eon/Source/Graphics/Color.cpp
  Eon/Source/Graphics/Mesh.cpp
  Eon/Source/Graphics/Renderer.cpp
  Eon/Source/Graphics/Shader.cpp
  Eon/Source/Graphics/Texture.cpp
  Eon/Source/Graphics/Vertex.cpp
  Eon/Source/Math/Mat4.cpp
  Eon/Source/Math/Vec2.cpp
  Eon/Source/Math/Vec3.cpp
  Eon/Source/Math/Vec4.cpp
  Eon/Source/Game.cpp
  Eon/Source/Timer.cpp
  Eon/Source/World.cpp)

add_executable(Sandbox Sandbox/Main.cpp)

target_link_libraries(Sandbox Eon ${SDL2_LIBRARY} ${SOIL_LIBRARIES} ${OPENGL_LIBRARIES})
