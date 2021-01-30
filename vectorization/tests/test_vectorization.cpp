#include <gtest/gtest.h>

#include <benchmark/benchmark.hpp>
#include <matrix/vectorized_matrix.hpp>
#include <matrix/standard_matrix.hpp>
#include <matrix/parent_matrix.hpp>

TEST(vectorized, StandardMultiplyTest) {
    ParentMatrix<StandardMatrix> matrix({ 8, 8, 8, 8 });
    ParentMatrix<StandardMatrix> matrix2({ 8, 8, 8, 8 });

    std::cout << Benchmark::getExecutionTime([&matrix, &matrix2](){
      for(int i = 0; i < 1000; i++) matrix.multiply(matrix2);
    }) << std::endl;

    std::cout << Benchmark::getExecutionTime([&matrix, &matrix2](){
      for(int i = 0; i < 1000; i++) matrix.multiply(matrix2);
    }) << std::endl;

    std::cout << Benchmark::getExecutionTime([&matrix, &matrix2](){
      for(int i = 0; i < 1000; i++) matrix.multiply(matrix2);
    }) << std::endl << std::endl;
}

TEST(vectorized, VectorizedMultiplyTest) {
    ParentMatrix<VectorizedMatrix> matrix({ 8, 8, 8, 8 });
    ParentMatrix<VectorizedMatrix> matrix2({ 8, 8, 8, 8 });

    std::cout << Benchmark::getExecutionTime([&matrix, &matrix2](){
      for(int i = 0; i < 1000; i++) matrix.multiply(matrix2);
    }) << std::endl;

    std::cout << Benchmark::getExecutionTime([&matrix, &matrix2](){
      for(int i = 0; i < 1000; i++) matrix.multiply(matrix2);
    }) << std::endl;

    std::cout << Benchmark::getExecutionTime([&matrix, &matrix2](){
      for(int i = 0; i < 1000; i++) matrix.multiply(matrix2);
    }) << std::endl;
}