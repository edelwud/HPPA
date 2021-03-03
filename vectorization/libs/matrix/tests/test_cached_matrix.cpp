#include <gtest/gtest.h>
#include <matrix/cached_matrix.hpp>
#include <matrix/vectorized_matrix.hpp>

#include <cmath>

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

TEST(cached_matrix, CompareWithStandardTest) {
    CachedMatrix matrix1(MATRIX_BLOCK_SIDE*10, MATRIX_BLOCK_SIDE*10);
    CachedMatrix matrix2(MATRIX_BLOCK_SIDE*10, MATRIX_BLOCK_SIDE*10);
    matrix1.multiply(&matrix2);

    VectorizedMatrix matrix3(MATRIX_BLOCK_SIDE*10, MATRIX_BLOCK_SIDE*10);
    VectorizedMatrix matrix4(MATRIX_BLOCK_SIDE*10, MATRIX_BLOCK_SIDE*10);
    matrix3.multiply(&matrix4);

    ASSERT_EQ(matrix1, matrix3);
}