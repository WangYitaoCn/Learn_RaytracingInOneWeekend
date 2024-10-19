# 指定CMake的最低版本
cmake_minimum_required(VERSION 3.16)

# 项目名称
project(Learn_RaytracingInOneWeekend)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定编译器标志（可选，调试模式）
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# 设置源文件目录，假设所有的源文件在src目录
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

# 将所有源文件添加到可执行文件
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES}
        src/main.cpp)

# 使用Ninja生成器
set(CMAKE_GENERATOR "Ninja")

# 如果有需要链接的库，可以使用以下命令链接库
# target_link_libraries(${PROJECT_NAME} some_library)

# 添加调试选项
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG_MODE)
endif()