#include <kernels/filter-operator.cuh>

#include <iostream>

__global__ void filterOperator(const char *filter, unsigned char *devSource, unsigned char *devDest, size_t pitch, int width, int height) {
    auto offsetX = (blockDim.x * blockIdx.x + threadIdx.x) * 4 + 1;
    auto offsetY = (blockDim.y * blockIdx.y + threadIdx.y) + 1;

    auto sharedX = threadIdx.x + 1;
    auto sharedY = threadIdx.y + 1;

    __shared__ char sharedMemory[18][130];

#pragma unroll
    for (int i = -1; i < 2; i++) {
        memcpy(
                sharedMemory[sharedY + i] + sharedX - 1,
                devSource + (offsetY + i) * pitch + offsetX - 1,
                6
        );
    }

    __syncthreads();

#pragma unroll
    for (int i = 0; i < 4; i++) {
        short result = 0;
#pragma unroll
        for (int l = -1, k = 0; k < 3; l++, k++) {
#pragma unroll
            for (int j = -1, m = 0; m < 3; j++, m++) {
                result += sharedMemory[sharedY + l][sharedX + j] * filter[k * 3 + m];
            }
        }

        result /= 9;
        if (result > 255)
            result = 255;

        memcpy(devDest + offsetY * pitch + offsetX + i, &result, 1);
    }
}