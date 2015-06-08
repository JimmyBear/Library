cmake_minimum_required(VERSION 2.6)
project(utility_test)

################################
# GTest
################################
include_directories(${CMAKE_SOURCE_DIR}/gtest-1.7.0/include)
include_directories(${CMAKE_SOURCE_DIR}/utility)

################################
# Unit Tests
################################
# Add test cpp file
add_executable(utility_test testStrConvert.cpp testFibonacci.cpp testLinkedList.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(utility_test gtest gtest_main)
target_link_libraries(utility_test utility)