cmake_minimum_required(VERSION 3.10)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(EulerLib STATIC EulerLib/EulerLib.cpp EulerLib/EulerLib.h)

add_executable(problem001 src/problem001.cpp)
target_include_directories(problem001 PRIVATE EulerLib)
