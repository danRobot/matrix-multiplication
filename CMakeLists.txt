cmake_minimum_required(VERSION 3.0)

project(matrix_mul)

find_package(OpenMP REQUIRED)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fopenmp")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(HEADER_UTILS_DIRECTORY include/utils)
set(SOURCE_UTILS_DIRECTORY src/utils)

set(HEADER_ALGO_DIRECTORY include/algorithms)
set(SOURCE_ALGO_DIRECTORY src/algorithms)

set(SOURCES main.cpp    ${SOURCE_UTILS_DIRECTORY}/utils.tpp
                        ${HEADER_UTILS_DIRECTORY}/utils.h
                        ${HEADER_UTILS_DIRECTORY}/types.h
                        
                        ${SOURCE_ALGO_DIRECTORY}/simple.tpp
                        ${HEADER_ALGO_DIRECTORY}/simple.h)

add_executable( matrix_mul ${SOURCES})
