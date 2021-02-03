#include <matrix/vectorized_matrix.hpp>
#include <matrix/parent_matrix.hpp>
#include <benchmark/benchmark.hpp>

#define ITERATIONS 5000

int main() {
    ParentMatrix<VectorizedMatrix> matrix({8,8,8,8});
    ParentMatrix<VectorizedMatrix> matrix2({8,8,8,8});

    std::cout << Benchmark::executeForSeveralTimes(ITERATIONS, [&matrix, &matrix2](){
      matrix.multiply(matrix2);
    });
    return 0;
}