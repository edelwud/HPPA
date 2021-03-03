#include <benchmark/benchmark.hpp>
#include <matrix/parent_matrix.hpp>
#include <matrix/cached_matrix.hpp>
#include <matrix/factory/vectorized_matrix.hpp>

int main() {
    VectorizedMatrixFactory factory;
    ParentMatrix matrix(
        {
            3,
            3,
            MATRIX_BLOCK_SIDE*2,
            MATRIX_BLOCK_SIDE*2
        },
        factory
    );
    ParentMatrix matrix2(
        {
            3,
            3,
            MATRIX_BLOCK_SIDE*2,
            MATRIX_BLOCK_SIDE*2
        },
        factory
    );
    std::cout << Benchmark::getExecutionTime(
        [&matrix, &matrix2](){
            matrix.multiply(matrix2);
        }
    );
    return 0;
}