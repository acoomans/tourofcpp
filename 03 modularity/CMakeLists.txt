cmake_minimum_required(VERSION 3.8)
project(modularity)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp vector.cpp vector.h)
add_executable(modularity ${SOURCE_FILES})