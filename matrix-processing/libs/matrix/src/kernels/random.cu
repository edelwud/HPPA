#include <kernels/random.cuh>

#include <curand.h>
#include <curand_kernel.h>

#include <utils/error_check.hpp>

__global__ void random(short* devMemory) {
    unsigned int i = (blockDim.x * blockIdx.x + threadIdx.x)*2;
    curandState state;
    curand_init(clock() + i, 0, 0, &state);

    unsigned int randomGenerated = curand(&state);
    memcpy(devMemory+i, &randomGenerated, sizeof(int));
}