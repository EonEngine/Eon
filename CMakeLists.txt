cmake_minimum_required(VERSION 2.8)

project(Eon)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake")
find_package(SOIL REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${GLEW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} glfw/include ${SOIL_INCLUDE_DIRS} Eon/Include)

add_subdirectory(glfw)
add_subdirectory(Eon)
add_subdirectory(Sandbox)
add_subdirectory(Tests)
