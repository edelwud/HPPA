#include <matrix/factory/standard_matrix.hpp>
#include <matrix/parent_matrix.hpp>
#include <benchmark/benchmark.hpp>

#define ITERATIONS 15000

int main() {
    StandardMatrixFactory factory;
    ParentMatrix matrix({8,8,8,8}, factory);
    ParentMatrix matrix2({8,8,8,8}, factory);

    std::cout << Benchmark::executeForSeveralTimes(ITERATIONS, [&matrix, &matrix2](){
      matrix.multiply(matrix2);
    });
    return 0;
}