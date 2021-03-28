#include <matrix-gpu.cuh>

#include <cuda.h>
#include <curand.h>

#include <kernels/random.cuh>
#include <kernels/processing.cuh>
#include <utils/error_check.hpp>

MatrixGPU::MatrixGPU(int n, int m) : Matrix(n, m) {}

void MatrixGPU::process() {
    launch(devSource, devDest, rows, columns);
    columns /= 2;
    rows *= 2;
    checkCudaErrors(cudaMemcpy(matrix, devDest, size, cudaMemcpyDeviceToHost));
}

void MatrixGPU::initialize() {
    checkCudaErrors(cudaMalloc((void**)&devSource, size));
    checkCudaErrors(cudaMalloc((void**)&devDest, size));
}

MatrixGPU::~MatrixGPU() {
    checkCudaErrors(cudaFree(devSource));
    checkCudaErrors(cudaFree(devDest));
}
