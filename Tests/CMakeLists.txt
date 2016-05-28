add_executable(Tests
  Tests.cpp
  Math.cpp)

find_package(GTest)
include_directories(. ${GTEST_INCLUDE_DIRS})

target_link_libraries(Tests Eon ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
