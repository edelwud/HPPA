#include <gtest/gtest.h>

#include <matrix/matrix-gpu.cuh>

TEST(matrix_gpu, ExecutionTimeTest) {
    MatrixGPU matrix(16, 16);
    matrix.initialize();
    matrix.print();
}