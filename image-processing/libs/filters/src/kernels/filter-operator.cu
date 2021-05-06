#include <kernels/filter-operator.cuh>

#include <iostream>

__global__ void filterOperator(std::map<int, int> &filter, short * devSource, short * devDest, size_t pitch, int width, int height) {
    uint2 offset = make_uint2(
            (blockDim.x * blockIdx.x + threadIdx.x + 1) * sizeof(short),
            (blockDim.y * blockIdx.y + threadIdx.y + 1) * sizeof(short)
    );

    devDest[0] = 1;
}