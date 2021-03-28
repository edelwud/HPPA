#include <gtest/gtest.h>

#include <matrix/matrix-cpu.hpp>

TEST(matrix_cpu, InitializeTest) {
    MatrixCPU matrix(100, 100);
    matrix.initialize();
}

TEST(matrix_cpu, ExecutionTest) {
    MatrixCPU matrix(20, 16);

    std::cout << "BEFORE:" << std::endl;
    matrix.initialize();
    matrix.print();

    std::cout << "AFTER:" << std::endl;
    matrix.process();
    matrix.print();
}