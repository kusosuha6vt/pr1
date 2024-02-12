cmake_minimum_required(VERSION 3.2)

project(pr1)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 11, 17, 20, 23
set(CMAKE_CXX_STANDARD 20)

include_directories(include)


add_definitions(-DLOG_ENABLED=0)
add_executable(ratio include/ratio.h include/menu.h src/main.cpp src/ratio.cpp)
