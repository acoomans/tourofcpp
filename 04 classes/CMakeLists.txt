cmake_minimum_required(VERSION 3.8)
project(04_classes)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp vector.cpp vector.h abstract_vector.h)
add_executable(04_classes ${SOURCE_FILES})