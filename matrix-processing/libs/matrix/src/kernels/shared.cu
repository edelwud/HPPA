#include <kernels/shared.cuh>

__global__ void reserve(short* devMemory, int n) {
    extern __shared__ int s[];
    int t = threadIdx.x;
    int tr = n-t-1;
    short* shortData = (short*)s;
    shortData[t] = devMemory[t];
    __syncthreads();
    devMemory[t] = shortData[tr];
}