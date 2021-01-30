cmake_minimum_required(VERSION 3.17)
project(vectorization)

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O2 -fno-tree-vectorize -fopt-info-vec-optimized")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3 -ftree-vectorize -fopt-info-vec-optimized")

set(VECTORIZATION_LIBS_DIR libs)
set(VECTORIZATION_DEPS matrix benchmark)

foreach(LIBRARY ${VECTORIZATION_DEPS})
    add_subdirectory("${VECTORIZATION_LIBS_DIR}/${LIBRARY}")
endforeach(LIBRARY)

add_subdirectory(src)
add_subdirectory(tests)