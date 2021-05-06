#include <iostream>

#include <benchmark/benchmark.hpp>
#include <benchmark/benchmark-gpu.cuh>
#include <matrix/matrix-cpu.hpp>
#include <matrix/matrix-gpu.cuh>

#define MATRIX_COLS 2048
#define MATRIX_ROWS 4096*5

int main() {
//    MatrixCPU matrixCpu(MATRIX_ROWS, MATRIX_COLS);
//    auto matrixCpuTime = Benchmark::executionTime([&matrixCpu](){
//        matrixCpu.initialize();
//        matrixCpu.process();
//    });

    cudaSetDevice(0);

    BenchmarkGPU::Start();
    MatrixGPU matrixGpu(MATRIX_ROWS*10, MATRIX_COLS);
    matrixGpu.initialize();
    matrixGpu.process();
    auto matrixGpuTime = BenchmarkGPU::End();

//    std::cout << "Matrix CPU time: " << matrixCpuTime << "ms" << std::endl;
    std::cout << "Matrix GPU time: " << matrixGpuTime << "ms" << std::endl;

    cudaDeviceReset();
    return 0;
}
