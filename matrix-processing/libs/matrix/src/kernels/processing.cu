#include <kernels/processing.cuh>

#include <curand_kernel.h>
#include <builtin_types.h>

#include <matrix.hpp>
#include <kernels/random.cuh>
#include <utils/error_check.hpp>

#include <iostream>

__global__ void processing(const unsigned char *devSource, unsigned char *devDest, long long rows, long long columns) {
    unsigned long long index = (blockDim.x*blockIdx.x+threadIdx.x)*4;
    unsigned int sharedIndex = threadIdx.x*4;

    __shared__ unsigned char sharedSource[64];
    memcpy(sharedSource + sharedIndex, devSource + index, 4);
    __syncthreads();

    unsigned long long sourceRow = index / columns;
    unsigned long long destOffset = index / 2 + sourceRow * columns / 2;

    memcpy(devDest + destOffset + columns / 2, sharedSource + sharedIndex, 2);
    memcpy(devDest + destOffset, sharedSource + sharedIndex + 2, 2);
}

void launchProcessing(unsigned char* matrix, unsigned char* devSource, unsigned char* devDest, long long rows, long long columns) {
    size_t size = rows*columns;
    cudaStream_t copySourceStream, launchStream;
    checkCudaErrors(cudaStreamCreate(&copySourceStream));
    checkCudaErrors(cudaStreamCreate(&launchStream));
    checkCudaErrors(cudaMemcpyAsync(devSource, matrix, size, cudaMemcpyHostToDevice, copySourceStream));

    size_t launchSize = size/4;
    dim3 threadsPerBlock(8);
    dim3 numBlocks((launchSize+threadsPerBlock.x-1)/threadsPerBlock.x);
    processing<<<numBlocks, threadsPerBlock, size, launchStream>>>(devSource, devDest, rows, columns);

    checkCudaErrors(cudaStreamDestroy(launchStream));
    checkCudaErrors(cudaStreamDestroy(copySourceStream));
}
