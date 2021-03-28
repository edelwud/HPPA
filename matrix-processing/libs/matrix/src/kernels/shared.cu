#include <kernels/shared.cuh>

__global__ void reserve(unsigned char* devMemory, int n) {
    extern __shared__ int s[];
    int t = threadIdx.x;
    int tr = n-t-1;
    auto* charData = (unsigned char*)s;
    charData[t] = devMemory[t];
    __syncthreads();
    devMemory[t] = charData[tr];
}