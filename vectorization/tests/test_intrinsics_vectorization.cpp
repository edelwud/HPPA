#include <gtest/gtest.h>

#include <benchmark/benchmark.hpp>
#include <matrix/vectorized_matrix.hpp>

#include "test_vectorization.hpp"

class IntrinsicsVectorizationTest : public VectorizationTest<VectorizedMatrix> {};

TEST_F(IntrinsicsVectorizationTest, IntrincsisMultiplyTest) {
    log(Benchmark::executeForSeveralTimes(1000, [this](){
      matrix->multiply(*matrix2);
    }));

    log(Benchmark::executeForSeveralTimes(1000, [this](){
      matrix->multiply(*matrix2);
    }));

    log(Benchmark::executeForSeveralTimes(1000, [this](){
      matrix->multiply(*matrix2);
    }));
}