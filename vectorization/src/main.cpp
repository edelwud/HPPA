#include <stdio.h>

#include <benchmark/benchmark.hpp>
#include <matrix/standard_matrix.hpp>
#include <matrix/parent_matrix.hpp>

int main() {
    ParentMatrix<StandardMatrix> matrix({ 18, 18, 18, 18 });
    ParentMatrix<StandardMatrix> matrix2({ 18, 18, 18, 18 });

    double time = Benchmark::getExecutionTime([&matrix, &matrix2](){
      for (int i = 0; i < 10; i++) matrix.multiply(matrix2);
    });
    printf("%f\n", time);

    time = Benchmark::getExecutionTime([&matrix, &matrix2](){
      for (int i = 0; i < 10; i++) matrix.multiply(matrix2);
    });
    printf("%f\n", time);

    time = Benchmark::getExecutionTime([&matrix, &matrix2](){
      for (int i = 0; i < 10; i++) matrix.multiply(matrix2);
    });
    printf("%f\n", time);
    return 0;
}
