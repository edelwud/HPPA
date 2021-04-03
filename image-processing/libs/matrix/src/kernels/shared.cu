#include <kernels/shared.cuh>

__global__ void reserve(unsigned char *devMemory, long long n) {
  extern __shared__ int s[];
  long long t = threadIdx.x;
  long long tr = n - t - 1;
  auto *charData = (unsigned char *)s;
  charData[t] = devMemory[t];
  __syncthreads();
  devMemory[t] = charData[tr];
}