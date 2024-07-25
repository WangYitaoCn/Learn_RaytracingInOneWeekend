cmake_minimum_required(VERSION 3.28)
project(Learn_RaytracingInOneWeekend)

set(CMAKE_CXX_STANDARD 17)

add_executable(Learn_RaytracingInOneWeekend main.cpp
        vec3.h
        color.h
        color.cpp
        Ray.h
        Ray.cpp)
