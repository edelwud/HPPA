cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME MatrixLib)
set(LIBRARY_NAMES matrix matrix-novec)

project(${PROJECT_NAME})

set(LIBRARY_HEADERS_DIR include/matrix)
set(LIBRARY_HEADERS
        ${LIBRARY_HEADERS_DIR}/matrix.hpp
        ${LIBRARY_HEADERS_DIR}/standard_matrix.hpp
        ${LIBRARY_HEADERS_DIR}/parent_matrix.hpp
        ${LIBRARY_HEADERS_DIR}/factory/matrix.hpp
        ${LIBRARY_HEADERS_DIR}/factory/standard_matrix.hpp
        ${LIBRARY_HEADERS_DIR}/factory/vectorized_matrix.hpp
        ${LIBRARY_HEADERS_DIR}/parent_matrix.hpp
        ${LIBRARY_HEADERS_DIR}/parent_matrix.hpp
        ${LIBRARY_HEADERS_DIR}/vectorized_matrix.hpp include/matrix/cached_matrix.hpp include/matrix/factory/cached_matrix.hpp)

set(LIBRARY_SOURCE_DIR src)
set(LIBRARY_SOURCE
        ${LIBRARY_SOURCE_DIR}/matrix.cpp
        ${LIBRARY_SOURCE_DIR}/standard_matrix.cpp
        ${LIBRARY_SOURCE_DIR}/parent_matrix.cpp
        ${LIBRARY_SOURCE_DIR}/vectorized_matrix.cpp src/cached_matrix.cpp)

foreach(LIBRARY_NAME ${LIBRARY_NAMES})
    add_library(
        ${LIBRARY_NAME}
            STATIC
                ${LIBRARY_HEADERS}
                ${LIBRARY_SOURCE})

    target_include_directories(
        ${LIBRARY_NAME}
            PRIVATE
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/matrix>
                $<INSTALL_INTERFACE:include/matrix>)

    target_include_directories(
        ${LIBRARY_NAME}
            PUBLIC
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                $<INSTALL_INTERFACE:include>)
endforeach(LIBRARY_NAME)

target_compile_options(matrix PRIVATE -O2 -ftree-vectorize -fopt-info-vec-optimized)
target_compile_options(matrix-novec PRIVATE -O2 -fno-tree-vectorize -fopt-info-vec-optimized)

add_subdirectory(tests)