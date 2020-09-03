cmake_minimum_required(VERSION 3.10)

add_library(EulerLib STATIC EulerLib/EulerLib.cpp EulerLib/EulerLib.h)

add_executable(problem001 src/problem001.cpp)
target_include_directories(problem001 PRIVATE EulerLib)
