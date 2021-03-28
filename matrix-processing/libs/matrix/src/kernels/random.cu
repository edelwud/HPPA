#include <kernels/random.cuh>

#include <curand.h>
#include <curand_kernel.h>

__global__ void random(unsigned char* devMemory) {
    unsigned int i = (blockDim.x * blockIdx.x + threadIdx.x)*4;
    curandState state;
    curand_init(clock() + i, 0, 0, &state);

    unsigned int randomGenerated = curand(&state);
    memcpy(devMemory+i, &randomGenerated, sizeof(int));
}

void launchRandom(unsigned char* devMemory, int rows, int columns) {
    size_t size = rows*columns/4;
    dim3 threadsPerBlock(4);
    dim3 numBlocks((size+threadsPerBlock.x-1)/threadsPerBlock.x);
    random<<<numBlocks, threadsPerBlock>>>(devMemory);
}