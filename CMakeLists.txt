# CMakeList.txt : CMake project for ghrendr, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(PROJECT_NAME "ghrendr")
project(${PROJECT_NAME})

set(EXEC_SOURCES
	src/Main.cpp
)

add_executable (${PROJECT_NAME} ${EXEC_SOURCES})


