#include <gtest/gtest.h>

#include <matrix/factory/standard_matrix.hpp>
#include <matrix/factory/vectorized_matrix.hpp>
#include <matrix/parent_matrix.hpp>
#include <matrix/standard_matrix.hpp>
#include <matrix/vectorized_matrix.hpp>

TEST(parent_matrix, AllocateTest) {
    StandardMatrixFactory factory;
    ParentMatrix matrix({ 1, 1, 1, 1 }, factory);
}

TEST(parent_matrix, MultiplyTest) {
    StandardMatrixFactory factory;
    ParentMatrix matrix({ 8, 8, 8, 8 }, factory);
    ParentMatrix matrix2({ 8, 8, 8, 8 }, factory);

    matrix.multiply(matrix2);
    matrix.print();
}

TEST(parent_matrix, ComparsionTest) {
    StandardMatrixFactory factory;
    ParentMatrix matrix({ 8, 8, 8, 8 }, factory);
    ParentMatrix matrix2({ 8, 8, 8, 8 }, factory);
    ASSERT_EQ(matrix, matrix2);

    VectorizedMatrixFactory factory2;
    ParentMatrix matrix3({ 8, 8, 8, 8 }, factory2);
    ParentMatrix matrix4({ 8, 8, 8, 8 }, factory2);
    ASSERT_EQ(matrix3, matrix4);
}