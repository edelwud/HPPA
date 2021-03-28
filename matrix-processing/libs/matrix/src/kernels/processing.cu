#include <kernels/processing.cuh>

#include <curand_kernel.h>
#include <builtin_types.h>

#include <matrix.hpp>
#include <kernels/random.cuh>
#include <utils/error_check.hpp>

#include <iostream>

__global__ void processing(const unsigned char *devSource, unsigned char *devDest, int rows, int columns) {
    unsigned int index = (blockDim.x*blockIdx.x+threadIdx.x)*4;

    if (index >= rows*columns)
        return;

    unsigned int sourceRow = index/columns;
    unsigned int destOffset = index/2+sourceRow*columns/2;

    memcpy(devDest+destOffset, devSource+index+2, 2);
    memcpy(devDest+destOffset+columns/2, devSource+index, 2);
}

void launchProcessing(unsigned char* devSource, unsigned char* devDest, int rows, int columns) {
    size_t size = rows*columns/4;
    dim3 threadsPerBlock(4);
    dim3 numBlocks((size+threadsPerBlock.x-1)/threadsPerBlock.x);
    processing<<<numBlocks, threadsPerBlock>>>(devSource, devDest, rows, columns);
}
