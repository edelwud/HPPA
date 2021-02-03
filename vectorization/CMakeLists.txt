cmake_minimum_required(VERSION 3.17)

include(cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.10.9.tar.gz"
        SHA1 "53b198e364dc7bc8360fc545f798563229bd7e20"
)

project(vectorization)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

set(VECTORIZATION_LIBS_DIR libs)
set(VECTORIZATION_DEPS matrix benchmark)

hunter_add_package(GTest)

foreach(LIBRARY ${VECTORIZATION_DEPS})
    add_subdirectory("${VECTORIZATION_LIBS_DIR}/${LIBRARY}")
endforeach(LIBRARY)

add_subdirectory(src)
add_subdirectory(tests)