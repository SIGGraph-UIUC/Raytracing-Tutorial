cmake_minimum_required(VERSION 3.10)
project(raytracer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    include/
)

set(HELPER_SOURCES
    src/util/color.cpp
    src/util/matrix.cpp
    src/util/tuple.cpp
)

set(RAYTRACER_SOURCES
    src/framebuffer.cpp
    src/camera.cpp
    src/scene.cpp
    src/geometry.cpp
    src/ray.cpp
    src/intersection.cpp
    src/payload.cpp
    src/light.cpp
    src/material.cpp
)

add_executable(raytracer src/main.cpp ${HELPER_SOURCES} ${RAYTRACER_SOURCES})
