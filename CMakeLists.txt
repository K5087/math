cmake_minimum_required(VERSION 4.2.0)

set(CMAKE_CXX_STANDARD 26)

project(math VERSION 0.0.1 LANGUAGES CXX)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE SOURCE_FILE ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_subdirectory(test)
