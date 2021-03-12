cmake_minimum_required(VERSION 3.17)

include(cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.10.9.tar.gz"
        SHA1 "53b198e364dc7bc8360fc545f798563229bd7e20"
)

project(cache_project)

set(CMAKE_CXX_STANDARD 14)

hunter_add_package(GTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(libs)
