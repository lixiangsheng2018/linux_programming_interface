cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(linux-programming-interface LANGUAGES C CXX)

SET(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(lib)
link_directories(${CMAKE_BINARY_DIR}/lib)

add_subdirectory(lib)
add_subdirectory(chp-03)
add_subdirectory(chp-04)
add_subdirectory(chp-05)