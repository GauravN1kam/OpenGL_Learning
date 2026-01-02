cmake_minimum_required(VERSION 4.0.1)
project(Projects VERSION 1.0.0 LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(
    Projects
    src/main.cpp
    src/triangle_mesh.cpp
    dependencies/glad/src/glad.c
)

target_include_directories(Projects PRIVATE
    dependencies/glad/include
)

target_link_libraries(Projects PRIVATE
    glfw
    OpenGL::GL
)
