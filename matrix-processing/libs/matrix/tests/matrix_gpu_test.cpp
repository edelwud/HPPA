#include <gtest/gtest.h>

#include <cuda.h>

#include <matrix/matrix-gpu.cuh>

TEST(matrix_gpu, InitializeTest) {
    MatrixGPU matrix(7, 8);
    matrix.initialize();
    matrix.print();
}

TEST(matrix_gpu, ExecutionTest) {
    MatrixGPU matrix(10, 16);
    matrix.initialize();
    matrix.process();
    matrix.print();
}