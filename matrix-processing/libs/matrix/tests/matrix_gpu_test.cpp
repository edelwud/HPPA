#include <gtest/gtest.h>

#include <cuda.h>

#include <matrix/matrix-gpu.cuh>

TEST(matrix_gpu, InitializeTest) {
    MatrixGPU matrix(7, 8);
    matrix.initialize();
    matrix.print();
}

TEST(matrix_gpu, ExecutionTest) {
    MatrixGPU matrix(20, 16);

    std::cout << "BEFORE:" << std::endl;
    matrix.initialize();
    matrix.print();

    std::cout << "AFTER:" << std::endl;
    matrix.process();
    matrix.print();
}