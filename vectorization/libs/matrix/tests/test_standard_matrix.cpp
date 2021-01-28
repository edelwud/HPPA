#include <gtest/gtest.h>
#include <matrix/standard_matrix.hpp>

TEST(matrix, AllocateTest) {
    StandardMatrix matrix(1, 2);
}

TEST(matrix, FillTest) {
    StandardMatrix matrix(1000, 2000);
}

TEST(matrix, PrintTest) {
    StandardMatrix matrix(5, 25);
    matrix.print();
}

TEST(matrix, MultiplyTest) {
    StandardMatrix matrix1(5, 5);
    StandardMatrix matrix2(5, 7);
    matrix1.multiply(matrix2)->print();
}