cmake_minimum_required(VERSION 3.8)
project(usertypes)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Vector_struct.cpp Vector_struct.h Vector_class.cpp Vector_class.h tagged_union.h enum.h tagged_union.cpp enum.cpp)
add_executable(usertypes ${SOURCE_FILES})