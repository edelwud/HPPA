#include <kernels/filter-operator-rgb.cuh>

__global__ void filterOperatorRGB(const char *filter, unsigned char *devSource, unsigned char *devDest, size_t pitch, int width, int height) {
    auto offsetX = (blockDim.x * blockIdx.x + threadIdx.x) * 4 + 1;
    auto offsetY = (blockDim.y * blockIdx.y + threadIdx.y) + 1;


#pragma unroll
    for (int i = 0; i < 4; i++) {
        short result = 0;
#pragma unroll
        for (int l = -1, k = 0; k < 3; l++, k++) {
#pragma unroll
            for (int j = -1, m = 0; m < 3; j++, m++) {
                result += devSource[(offsetY + l) * pitch + offsetX + j + i] * filter[k * 3 + m];
            }
        }

        result /= 9;
        if (result > 255)
            result = 255;

        if (result < 0)
            result = 0;

        result += 100;

        memcpy(devDest + offsetY * pitch + offsetX + i, &result, 1);
    }
}