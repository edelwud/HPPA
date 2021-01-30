#include <gtest/gtest.h>
#include <matrix/standard_matrix.hpp>
#include <matrix/vectorized_matrix.hpp>

TEST(vectorized_matrix, AllocateTest) {
    VectorizedMatrix matrix(1, 2);
}

TEST(vectorized_matrix, FillTest) {
    VectorizedMatrix matrix(1000, 2000);
}

TEST(vectorized_matrix, MultiplyTest) {
    VectorizedMatrix matrix1(100, 100);
    VectorizedMatrix matrix2(100, 100);
    matrix1.multiply(matrix2)->print();
}

TEST(vectorized_matrix, CompareWithStandardTest) {
    StandardMatrix matrix1(100, 100);
    StandardMatrix matrix2(100, 100);
    matrix1.multiply(matrix2)->print();
}