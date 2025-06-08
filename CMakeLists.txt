cmake_minimum_required(VERSION 3.0)

project(matrix_mul)
set(CMAKE_CXX_STANDARD 20)

set(HEADER_UTILS_DIRECTORY include/utils)
set(SOURCE_UTILS_DIRECTORY src/utils)

set(HEADER_ALGO_DIRECTORY include/algorithms)
set(SOURCE_ALGO_DIRECTORY src/algorithms)

set(SOURCES main.cpp    ${SOURCE_UTILS_DIRECTORY}/utils.cpp
                        ${HEADER_UTILS_DIRECTORY}/utils.h
                        ${HEADER_UTILS_DIRECTORY}/types.h
                        
                        ${SOURCE_ALGO_DIRECTORY}/simple.cpp
                        ${HEADER_ALGO_DIRECTORY}/simple.h)

add_executable( matrix_mul ${SOURCES})
