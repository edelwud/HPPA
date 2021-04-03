#include <benchmark.cuh>

#include <cuda.h>
#include <curand.h>

#include <kernels/processing.cuh>
#include <kernels/random.cuh>
#include <utils/error_check.hpp>

MatrixGPU::MatrixGPU(long long n, long long m) : Matrix(n, m) {}

void MatrixGPU::process() {
  unsigned char *devSource;
  unsigned char *devDest;
  checkCudaErrors(cudaMalloc((void **)&devSource, size));
  checkCudaErrors(cudaMalloc((void **)&devDest, size));

  launchProcessing(matrix, devSource, devDest, rows, columns);

  columns /= 2;
  rows *= 2;

  checkCudaErrors(cudaMemcpy(matrix, devDest, size, cudaMemcpyDeviceToHost));

  checkCudaErrors(cudaFree(devSource));
  checkCudaErrors(cudaFree(devDest));
}

void MatrixGPU::initialize() {
  unsigned char *devMemory;
  checkCudaErrors(cudaMalloc((void **)&devMemory, size));

  launchRandom(devMemory, rows, columns);

  checkCudaErrors(cudaMemcpy(matrix, devMemory, size, cudaMemcpyDeviceToHost));

  checkCudaErrors(cudaFree(devMemory));
}
