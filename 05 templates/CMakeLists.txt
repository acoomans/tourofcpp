cmake_minimum_required(VERSION 3.8)
project(05_templates)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp vector.cpp vector.h LessThan.cpp LessThan.h variadic.cpp variadic.h)
add_executable(05_templates ${SOURCE_FILES})