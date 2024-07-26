cmake_minimum_required(VERSION 3.28)
project(Learn_RaytracingInOneWeekend)

set(CMAKE_CXX_STANDARD 17)

# 设置输出目录为build/debug
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/debug)
# 设置Release版本的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/release)
add_executable(Learn_RaytracingInOneWeekend main.cpp
        vec3.h
        color.h
        color.cpp
        Ray.h
        Ray.cpp)
