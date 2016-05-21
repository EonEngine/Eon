cmake_minimum_required(VERSION 3.5)

project(Eon)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} Eon/Include)
add_library(Eon 
  Eon/Source/Entity/Entity.cpp
  Eon/Source/Entity/Component.cpp
  Eon/Source/Renderer/Renderer.cpp 
  Eon/Source/Renderer/SDL.cpp)

add_executable(Sandbox Sandbox/Main.cpp)

target_link_libraries(Sandbox Eon ${SDL2_LIBRARY})
