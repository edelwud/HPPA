#include <gtest/gtest.h>

#include <benchmark/benchmark.hpp>
#include <matrix/factory/standard_matrix.hpp>

#include "test_vectorization.hpp"

class StandardVectorizationTest : public VectorizationTest<StandardMatrixFactory> {};

TEST_F(StandardVectorizationTest, StandardMultiplyTest) {
    matrix->multiply(*matrix2);
}