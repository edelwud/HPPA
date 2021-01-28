#include <gtest/gtest.h>
#include <matrix/matrix.hpp>

TEST(matrix, AllocateTest) {
    Matrix matrix(1, 2);
}

TEST(matrix, FillTest) {
    Matrix matrix(1000, 2000);
}

TEST(matrix, PrintTest) {
    Matrix matrix(5, 25);
    matrix.print();
}

TEST(matrix, MultiplyTest) {
    Matrix matrix1(5, 5);
    Matrix matrix2(5, 7);
    matrix1.multiply(matrix2)->print();
}