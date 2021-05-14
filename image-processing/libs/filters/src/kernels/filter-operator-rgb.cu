#include <kernels/filter-operator-rgb.cuh>

__device__ unsigned char fixIntensity(int intensity) {
    if (intensity > 255)
        return 255;

    if (intensity < 0)
        return 0;

    return (unsigned char) intensity;
}

__global__ void filterOperatorRGB(const char *filter, unsigned char *devSource, unsigned char *devDest, size_t pitch, int width, int height) {
    auto offsetX = (blockDim.x * blockIdx.x + threadIdx.x) * 3 + 3;
    auto offsetY = (blockDim.y * blockIdx.y + threadIdx.y) + 1;

    auto sharedX = threadIdx.x * 9;
    auto sharedY = threadIdx.y + 1;

    __shared__ unsigned char sharedMemory[16 + 2][(32 + 2) * 9];
    for (int i = -1; i < 2; i++) {
        memcpy(
                sharedMemory[sharedY + i] + sharedX,
                devSource + (offsetY + i) * pitch + offsetX - 3,
                9);
    }

    __syncthreads();

    int r = 0;
    int g = 0;
    int b = 0;
#pragma unroll
    for (int i = 0; i < 3; i++) {
#pragma unroll
        for (int j = 0; j < 3; j++) {
            r += sharedMemory[sharedY + i - 1][sharedX + j * 3] * filter[i * 3 + j] / 9;
            g += sharedMemory[sharedY + i - 1][sharedX + j * 3 + 1] * filter[i * 3 + j] / 9;
            b += sharedMemory[sharedY + i - 1][sharedX + j * 3 + 2] * filter[i * 3 + j] / 9;
        }
    }

    r = fixIntensity(r);
    g = fixIntensity(g);
    b = fixIntensity(b);

    memcpy(devDest + offsetY * pitch + offsetX, &r, 1);
    memcpy(devDest + offsetY * pitch + offsetX + 1, &g, 1);
    memcpy(devDest + offsetY * pitch + offsetX + 2, &b, 1);
}