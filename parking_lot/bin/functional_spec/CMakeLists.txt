cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(run_functional_tests test.cpp function_need_to_test.cpp)
target_link_libraries(run_functional_tests ${GTEST_LIBRARIES} pthread)
