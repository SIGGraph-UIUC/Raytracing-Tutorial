cmake_minimum_required(VERSION 3.10)
project(raytracer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    include/
)

set(RAYTRACER_SOURCES
    src/framebuffer.cpp
    src/camera.cpp
    src/scene.cpp
    src/geometry.cpp
)

add_executable(raytracer src/main.cpp ${RAYTRACER_SOURCES})
