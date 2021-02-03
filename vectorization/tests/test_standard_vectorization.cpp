#include <gtest/gtest.h>

#include <benchmark/benchmark.hpp>
#include <matrix/factory/standard_matrix.hpp>

#include "test_vectorization.hpp"

class StandardVectorizationTest : public VectorizationTest<StandardMatrixFactory> {};

TEST_F(StandardVectorizationTest, StandardMultiplyTest) {
    log(Benchmark::executeForSeveralTimes(ITERATIONS, [this](){
      matrix->multiply(*matrix2);
    }));

    log(Benchmark::executeForSeveralTimes(ITERATIONS, [this](){
      matrix->multiply(*matrix2);
    }));

    log(Benchmark::executeForSeveralTimes(ITERATIONS,[this](){
      matrix->multiply(*matrix2);
    }));
}