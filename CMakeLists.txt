cmake_minimum_required(VERSION 3.5)

project(Eon)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake")
find_package(SDL2 REQUIRED)
find_package(SOIL REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SOIL_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} Eon/Include)

add_subdirectory(Eon)
add_subdirectory(Sandbox)
add_subdirectory(Tests)
