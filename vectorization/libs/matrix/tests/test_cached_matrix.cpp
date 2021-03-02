#include <gtest/gtest.h>
#include <matrix/cached_matrix.hpp>
#include <matrix/vectorized_matrix.hpp>

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
    CachedMatrix matrix1(100, 100);
    CachedMatrix matrix2(100, 100);
    matrix1.multiply(&matrix2);

    VectorizedMatrix matrix3(100, 100);
    VectorizedMatrix matrix4(100, 100);
    matrix3.multiply(&matrix4);

    ASSERT_EQ(matrix1, matrix3);
}