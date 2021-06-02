cmake_minimum_required(VERSION 3.17)

include(cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.214.tar.gz"
        SHA1 "e14bc153a7f16d6a5eeec845fb0283c8fad8c358"
)

set(CMAKE_CUDA_COMPILER /opt/cuda/bin/nvcc)

get_filename_component(PROJECT ${CMAKE_CURRENT_SOURCE_DIR} NAME_WLE)

project(${PROJECT} CUDA C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CUDA_STANDARD 11)
set(CMAKE_CUDA_SEPARABLE_COMPILATION ON)
set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -rdc=true")

hunter_add_package(GTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(libs)
