cmake_minimum_required(VERSION 3.22)

project(2d)

add_subdirectory(3rd/glfw)
add_subdirectory(3rd/spdlog)

file(GLOB GLAD_FILES 3rd/glad/src/glad.c)
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(2d ${SRC_FILES} ${GLAD_FILES})

target_include_directories(2d PRIVATE include 3rd/glad/include)
target_link_libraries(2d PRIVATE glfw spdlog)
