cmake_minimum_required(VERSION 3.10)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(EulerLib STATIC
		EulerLib/EulerLib.cpp 
		EulerLib/EulerLib.h
	)

add_executable(projectEuler
	src/main.cpp
	src/problems.cpp
	src/problem001.cpp
	src/problem002.cpp
	src/problem003.cpp
	src/problem004.cpp
	src/problem005.cpp
	src/problem006.cpp
	src/problem007.cpp
	src/problem008.cpp
	src/problem009.cpp
	src/problem010.cpp
	src/problem011.cpp
	src/problem012.cpp
	src/problem013.cpp
	src/problem014.cpp
	src/problem015.cpp
	src/problem016.cpp
	src/problem017.cpp
	src/problem018.cpp
	src/problem019.cpp
	src/problem020.cpp
	src/problem021.cpp
	src/problem022.cpp
	src/problem023.cpp
	src/problem024.cpp
	src/problem025.cpp
	src/problem026.cpp
	src/problem027.cpp

	EulerLib/EulerLib.h
	)
target_link_libraries(projectEuler EulerLib)
target_include_directories(projectEuler PRIVATE EulerLib src/inc)
