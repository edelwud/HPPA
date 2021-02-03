#include <matrix/standard_matrix.hpp>
#include <matrix/parent_matrix.hpp>
#include <benchmark/benchmark.hpp>

#define ITERATIONS 5000

int main() {
    ParentMatrix<StandardMatrix> matrix({8,8,8,8});
    ParentMatrix<StandardMatrix> matrix2({8,8,8,8});

    std::cout << Benchmark::executeForSeveralTimes(ITERATIONS, [&matrix, &matrix2](){
      matrix.multiply(matrix2);
    });
    return 0;
}