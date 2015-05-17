cmake_minimum_required (VERSION 2.6)

include_directories(${CMAKE_SOURCE_DIR}/utility)
 
project(JBTest)
add_executable(JBTest main.cpp)
target_link_libraries(JBTest utility)