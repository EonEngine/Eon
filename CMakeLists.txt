cmake_minimum_required(VERSION 3.5)

project(Eon)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake")
find_package(PkgConfig REQUIRED)
find_package(SOIL REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${GLEW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${SOIL_INCLUDE_DIRS} Eon/Include)

add_subdirectory(Eon)
add_subdirectory(Sandbox)
add_subdirectory(Tests)
