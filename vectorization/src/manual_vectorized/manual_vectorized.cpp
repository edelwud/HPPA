#include <matrix/factory/vectorized_matrix.hpp>
#include <matrix/parent_matrix.hpp>
#include <benchmark/benchmark.hpp>

int main() {
    VectorizedMatrixFactory factory;
    ParentMatrix matrix({256,256,8,8}, factory);
    ParentMatrix matrix2({256,256,8,8}, factory);
    std::cout << Benchmark::getExecutionTime([&matrix, &matrix2](){matrix.multiply(matrix2);});

    return 0;
}