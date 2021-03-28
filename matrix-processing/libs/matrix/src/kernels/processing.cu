#include <kernels/processing.cuh>

#include <curand_kernel.h>
#include <builtin_types.h>

#include <matrix.hpp>
#include <kernels/random.cuh>
#include <utils/error_check.hpp>

#include <iostream>

__global__ void process(const char *devSource, char *devDest, int rows, int columns) {
    unsigned int index = (blockDim.x*blockIdx.x+threadIdx.x)*4;

    if (index >= rows*columns)
        return;

    unsigned int sourceRow = index/columns;
    unsigned int destOffset = index/2+sourceRow*columns/2;

    memcpy(devDest+destOffset, devSource+index+2, 2);
    memcpy(devDest+destOffset+columns/2, devSource+index, 2);
}

void launch(char* devSource, char* devDest, int rows, int columns) {
    size_t size = rows*columns/4;
    dim3 threadsPerBlock(4);
    dim3 numBlocks((size+threadsPerBlock.x-1)/threadsPerBlock.x);

    random<<<numBlocks, threadsPerBlock>>>(devSource);

    char *arr = new char[rows*columns];
    checkCudaErrors(cudaMemcpy(arr, devSource, rows*columns, cudaMemcpyDeviceToHost));

    std::cout << "RANDOMIZED:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d ", arr[i*columns + j]);
        }
        std::cout << std::endl;
    }

    std::cout << "FLEX:" << std::endl;
    process<<<numBlocks, threadsPerBlock>>>(devSource, devDest, rows, columns);
}
