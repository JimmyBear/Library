cmake_minimum_required(VERSION 2.6)
project(network_test)

################################
# GTest
################################
include_directories(${CMAKE_SOURCE_DIR}/gtest-1.7.0/include)
include_directories(${CMAKE_SOURCE_DIR}/network)

################################
# Unit Tests
################################
# Add test cpp file
add_executable(network_test testIPEndPoint.cpp testSocket.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(network_test gtest gtest_main)
target_link_libraries(network_test network)