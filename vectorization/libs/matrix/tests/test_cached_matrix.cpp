#include <gtest/gtest.h>

#include <matrix/cached_matrix.hpp>
#include <matrix/vectorized_matrix.hpp>
#include <matrix/parent_matrix.hpp>
#include <matrix/factory/vectorized_matrix.hpp>
#include <matrix/factory/cached_matrix.hpp>

TEST(cached_matrix, AllocateTest) {
    CachedMatrix matrix(1, 2);
}

TEST(cached_matrix, FillTest) {
    CachedMatrix matrix(1000, 2000);
}

TEST(cached_matrix, MultiplyTest) {
    CachedMatrix matrix1(100, 100);
    CachedMatrix matrix2(100, 100);
    matrix1.multiply(&matrix2);
    matrix1.print();
}

TEST(cached_matrix, AddMatrixTest) {
    CachedMatrix matrix1(8, 8);
    CachedMatrix matrix2(8, 8);
    matrix1.add(&matrix2);
    matrix1.print();
}

TEST(cached_matrix, CompareWithVectorizedTest) {
    CachedMatrix matrix1(MATRIX_BLOCK_SIDE, MATRIX_BLOCK_SIDE);
    CachedMatrix matrix2(MATRIX_BLOCK_SIDE, MATRIX_BLOCK_SIDE);
    matrix1.multiply(&matrix2);

    VectorizedMatrix matrix3(MATRIX_BLOCK_SIDE, MATRIX_BLOCK_SIDE);
    VectorizedMatrix matrix4(MATRIX_BLOCK_SIDE, MATRIX_BLOCK_SIDE);
    matrix3.multiply(&matrix4);

    ASSERT_EQ(matrix1, matrix3);
}

TEST(cached_matrix, CompareWithParentTest) {
    CachedMatrixFactory factory;
    ParentMatrix matrix(
        {
            2,
            2,
            MATRIX_BLOCK_SIDE*2,
            MATRIX_BLOCK_SIDE*2
        },
        factory
    );
    ParentMatrix matrix2(
        {
            2,
            2,
            MATRIX_BLOCK_SIDE*2,
            MATRIX_BLOCK_SIDE*2
        },
        factory
    );
    matrix.multiply(matrix2);

    VectorizedMatrixFactory factoryVec;
    ParentMatrix matrix3(
        {
            2,
            2,
            MATRIX_BLOCK_SIDE*2,
            MATRIX_BLOCK_SIDE*2
        },
        factoryVec
    );
    ParentMatrix matrix4(
        {
            2,
            2,
            MATRIX_BLOCK_SIDE*2,
            MATRIX_BLOCK_SIDE*2
        },
        factoryVec
    );
    matrix3.multiply(matrix4);

    ASSERT_EQ(matrix, matrix3);
}