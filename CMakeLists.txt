cmake_minimum_required(VERSION 3.10)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(EulerLib STATIC EulerLib/EulerLib.cpp EulerLib/EulerLib.h)

add_executable(problem001 src/problem001.cpp)
target_include_directories(problem001 PRIVATE EulerLib)

add_executable(problem002 src/problem002.cpp)
target_include_directories(problem002 PRIVATE EulerLib)

add_executable(problem003 src/problem003.cpp)
target_include_directories(problem003 PRIVATE EulerLib)
target_link_libraries(problem003 EulerLib)

add_executable(problem004 src/problem004.cpp)
target_include_directories(problem004 PRIVATE EulerLib)
target_link_libraries(problem004 EulerLib)

add_executable(problem005 src/problem005.cpp)
target_include_directories(problem005 PRIVATE EulerLib)
target_link_libraries(problem005 EulerLib)

add_executable(problem006 src/problem006.cpp)
target_include_directories(problem006 PRIVATE EulerLib)
target_link_libraries(problem006 EulerLib)

add_executable(problem007 src/problem007.cpp)
target_include_directories(problem007 PRIVATE EulerLib)
target_link_libraries(problem007 EulerLib)

add_executable(problem008 src/problem008.cpp)
target_include_directories(problem008 PRIVATE EulerLib)
target_link_libraries(problem008 EulerLib)

add_executable(problem009 src/problem009.cpp)
target_include_directories(problem009 PRIVATE EulerLib)

add_executable(problem010 src/problem010.cpp)
target_include_directories(problem010 PRIVATE EulerLib)
target_link_libraries(problem010 EulerLib)

