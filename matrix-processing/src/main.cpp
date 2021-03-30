#include <iostream>

#include <benchmark/benchmark.hpp>
#include <matrix/matrix-cpu.hpp>
#include <matrix/matrix-gpu.cuh>

#define MATRIX_COLS 4096*10
#define MATRIX_ROWS 4096*5

int main() {
    MatrixCPU matrixCpu(MATRIX_ROWS, MATRIX_COLS);
    auto matrixCpuTime = Benchmark::executionTime([&matrixCpu](){
//        matrixCpu.initialize();
//        matrixCpu.process();
    });

    MatrixGPU matrixGpu(MATRIX_ROWS*2, MATRIX_COLS);
    auto matrixGpuTime = Benchmark::executionTime([&matrixGpu](){
        matrixGpu.initialize();
        matrixGpu.process();
    });

    std::cout << "Matrix CPU time: " << matrixCpuTime << "ms" << std::endl;
    std::cout << "Matrix GPU time: " << matrixGpuTime << "ms" << std::endl;

    return 0;
}
