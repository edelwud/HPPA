#include <gtest/gtest.h>

#include <matrix/factory/standard_matrix.hpp>
#include <matrix/factory/vectorized_matrix.hpp>
#include <matrix/matrix.hpp>
#include <matrix/parent_matrix.hpp>

TEST(CommonMatrixTest, ParentMatrixComparsionTest) {
    StandardMatrixFactory factory;
    ParentMatrix standardMatrix({ 8, 8, 8, 8 }, factory);
    ParentMatrix standardMatrix2({ 8, 8, 8, 8 }, factory);
    standardMatrix.multiply(standardMatrix2);

    VectorizedMatrixFactory factory2;
    ParentMatrix vectorizedMatrix({ 8, 8, 8, 8 }, factory2);
    ParentMatrix vectorizedMatrix2({ 8, 8, 8, 8 }, factory2);
    vectorizedMatrix.multiply(vectorizedMatrix2);

    ASSERT_EQ(standardMatrix, vectorizedMatrix);
}