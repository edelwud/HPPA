cmake_minimum_required(VERSION 3.17)

include(cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.10.9.tar.gz"
        SHA1 "53b198e364dc7bc8360fc545f798563229bd7e20"
)

get_filename_component(PROJECT ${CMAKE_CURRENT_SOURCE_DIR} NAME_WLE)
project(${PROJECT} CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_ARCHITECTURES 50)
set(CMAKE_CUDA_SEPARABLE_COMPILATION ON)
set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -rdc=true")

hunter_add_package(GTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(libs)
