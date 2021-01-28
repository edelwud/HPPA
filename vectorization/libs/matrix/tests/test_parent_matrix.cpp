#include <gtest/gtest.h>
#include <matrix/parent_matrix.hpp>
#include <matrix/standard_matrix.hpp>

TEST(parent_matrix, AllocateTest) {
    ParentMatrix<StandardMatrix> matrix({ 1, 1, 1, 1 });
}

TEST(parent_matrix, MultiplyTest) {
    ParentMatrix<StandardMatrix> matrix({ 8, 8, 8, 8 });
    ParentMatrix<StandardMatrix> matrix2({ 8, 8, 8, 8 });

    matrix.multiply(matrix2)->print();
}