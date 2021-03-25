#include <matrix-gpu.cuh>

#include <curand.h>

#include <kernels/random.cuh>
#include <utils/error_check.hpp>

MatrixGPU::MatrixGPU(int n, int m) : Matrix(n, m) {}

void MatrixGPU::process() {

}

void MatrixGPU::initialize() {
    short* devData;
    checkCudaErrors(cudaMalloc((void**)&devData, rows*columns*sizeof(short)));
    random<<<1, rows*columns/2>>>(devData);
    checkCudaErrors(cudaMemcpy(matrix, devData, rows * columns * sizeof(short), cudaMemcpyDeviceToHost));
}
