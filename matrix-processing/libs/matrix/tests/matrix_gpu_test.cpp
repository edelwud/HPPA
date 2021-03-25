#include <gtest/gtest.h>

#include <matrix/matrix-gpu.cuh>

TEST(matrix_gpu, ExecutionTimeTest) {
    MatrixGPU matrix(7, 8);
    matrix.initialize();
    matrix.print();
}