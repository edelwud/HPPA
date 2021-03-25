#include <gtest/gtest.h>

#include <matrix/matrix-cpu.hpp>

TEST(matrix_cpu, ExecutionTimeTest) {
    MatrixCPU matrix(1024*12, 1024*12);
    matrix.initialize();
    matrix.process();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}