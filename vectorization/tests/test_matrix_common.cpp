#include <gtest/gtest.h>

#include <matrix/matrix.hpp>
#include <matrix/parent_matrix.hpp>
#include <matrix/standard_matrix.hpp>
#include <matrix/vectorized_matrix.hpp>

TEST(CommonMatrixTest, ParentMatrixComparsionTest) {
    ParentMatrix<StandardMatrix> standardMatrix({ 8, 8, 8, 8 });
    ParentMatrix<StandardMatrix> standardMatrix2({ 8, 8, 8, 8 });
    auto stdResult = standardMatrix.multiply(standardMatrix2);

    ParentMatrix<StandardMatrix> vectorizedMatrix({ 8, 8, 8, 8 });
    ParentMatrix<StandardMatrix> vectorizedMatrix2({ 8, 8, 8, 8 });
    auto vecResult = vectorizedMatrix.multiply(vectorizedMatrix2);

    ASSERT_EQ(*stdResult, *vecResult);
}