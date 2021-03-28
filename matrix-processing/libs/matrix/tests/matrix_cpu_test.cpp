#include <gtest/gtest.h>

#include <matrix/matrix-cpu.hpp>

TEST(matrix_cpu, InitializeTest) {
    MatrixCPU matrix(100, 100);
    matrix.initialize();
}

TEST(matrix_cpu, ExecutionTest) {
    MatrixCPU matrix(10, 10);
    matrix.initialize();
    std::cout << "BEFORE:" << std::endl;
    matrix.print();
    matrix.process();
    std::cout << "AFTER:" << std::endl;
    matrix.print();
}