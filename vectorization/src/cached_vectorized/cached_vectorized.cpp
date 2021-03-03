#include <matrix/cached_matrix.hpp>
#include <matrix/parent_matrix.hpp>
#include <benchmark/benchmark.hpp>

int main() {
    CachedMatrix matrix(MATRIX_BLOCK_SIDE*5, MATRIX_BLOCK_SIDE*5);
    CachedMatrix matrix2(MATRIX_BLOCK_SIDE*5, MATRIX_BLOCK_SIDE*5);
    std::cout << Benchmark::getExecutionTime([&matrix, &matrix2](){matrix.multiply(&matrix2);});
    return 0;
}