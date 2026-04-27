set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(main main.cpp)
target_include_directories(main PRIVATE ${INCLUDE_DIR})
message(STATUS "INCLUDE_DIR = [${INCLUDE_DIR}]")
