#include <gtest/gtest.h>

#include <benchmark/benchmark.hpp>
#include <matrix/factory/vectorized_matrix.hpp>

#include "test_vectorization.hpp"

class IntrinsicsVectorizationTest : public VectorizationTest<VectorizedMatrixFactory> {};

TEST_F(IntrinsicsVectorizationTest, IntrincsisMultiplyTest) {
    log(Benchmark::executeForSeveralTimes(ITERATIONS, [this](){
      matrix->multiply(*matrix2);
    }));

    log(Benchmark::executeForSeveralTimes(ITERATIONS, [this](){
      matrix->multiply(*matrix2);
    }));

    log(Benchmark::executeForSeveralTimes(ITERATIONS, [this](){
      matrix->multiply(*matrix2);
    }));
}