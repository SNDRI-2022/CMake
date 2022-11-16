# 指定CMake支持的最低版本(VERSION为必写项)
cmake_minimum_required(VERSION 3.10)

# 设置项目名称(VERSION为可写项)
project(CXX11 VERSION 0.1.0)

# 让CMAKE支持C++11
# 让CMAKE强制按C++11执行
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# 添加可执行文件
add_executable(CXX11 main.cpp)