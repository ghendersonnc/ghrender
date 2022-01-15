# CMakeList.txt : CMake project for ghrendr, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(PROJECT_NAME "ghrendr")
project(${PROJECT_NAME})


include_directories(include)

# imgui
set(IMGUI_PATH external/imgui)
file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp)
add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC ${IMGUI_PATH})

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)

# GLAD
set(GLAD_PATH include/glad)
#file(GLOB GLAD_SOURCES ${GLAD_PATH}/*.c)
add_library(glad STATIC ${GLAD_PATH}/glad.c)
target_include_directories(glad PUBLIC ${GLAD_PATH})

# glm
add_subdirectory(external/glm)

# stb_image
set(STB_IMAGE_PATH include/stb_image)
file(GLOB STB_IMAGE_SOURCES ${STB_IMAGE_PATH}/*.cpp)
add_library(stb_image STATIC ${STB_IMAGE_SOURCES})
target_include_directories(stb_image PUBLIC ${STB_IMAGE_PATH})

# execs
set(EXEC_SOURCES
	src/Platform/Windows/Win32Window.cpp
	src/Core/Application.cpp
	src/Core/Window.cpp
	src/Error/ghassert.cpp
	src/Main.cpp
)

set(EXEC_HEADERS
	src/Platform/Windows/Win32Window.h
	src/Core/Application.h
	src/Core/Window.h
	src/Core/KeyCodes.h
	src/Events/KeyboardEvents.h
	src/Events/Event.h
	src/Events/MouseEvents.h
	src/Error/ghassert.hpp
)

add_executable (${PROJECT_NAME} ${EXEC_SOURCES} ${EXEC_HEADERS})

target_link_libraries(${PROJECT_NAME}
	PUBLIC glad
	PUBLIC glfw
	PUBLIC glm::glm
	PUBLIC stb_image
	PUBLIC imgui
)

# Eventual tests
add_subdirectory(external/catch2)

add_executable(tests 
	tests/Tests.cpp
)
target_link_libraries(tests
	PRIVATE Catch2::Catch2WithMain
)
