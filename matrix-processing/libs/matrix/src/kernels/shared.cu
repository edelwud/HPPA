#include <kernels/shared.cuh>

__global__ void reserve(char* devMemory, int n) {
    extern __shared__ int s[];
    int t = threadIdx.x;
    int tr = n-t-1;
    char* charData = (char*)s;
    charData[t] = devMemory[t];
    __syncthreads();
    devMemory[t] = charData[tr];
}