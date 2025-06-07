cmake_minimum_required(VERSION 3.0)

project(matrix_mul)
set(CMAKE_CXX_STANDARD 20)

set(HEADER_DIRECTORY include/)
set(SOURCE_DIRECTORY src/)

set(SOURCES main.cpp ${SOURCE_DIRECTORY}/functions.cpp ${HEADER_DIRECTORY}/functions.h)

add_executable( matrix_mul ${SOURCES})
