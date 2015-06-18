cmake_minimum_required(VERSION 2.6)
project(practice_test)

################################
# GTest
################################
include_directories(${CMAKE_SOURCE_DIR}/gtest-1.7.0/include)
include_directories(${CMAKE_SOURCE_DIR}/practice)

################################
# Unit Tests
################################
# Add test cpp file
add_executable(practice_test testStrPermutation.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(practice_test gtest gtest_main)
target_link_libraries(practice_test practice)