#include <kernels/launcher-rgb.cuh>

#include <filters/kernels/filter-operator-rgb.cuh>
#include <utils/error_check.hpp>
#include <utils/helpers/helper_border_rgb.hpp>

float launchRGB(char *filter, Loader::Image &image) {

    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    image.width *= 3;

    image.data = addImageBorderRGB(image.data, image.height, image.width);
    image.width += 6;
    image.height += 2;

    unsigned char *devSource;
    unsigned char *devDest;
    char *devFilter;
    size_t pitch;

    checkCudaErrors(cudaMalloc(&devFilter, 9));
    checkCudaErrors(cudaMemcpy(devFilter, filter, 9, cudaMemcpyHostToDevice));

    checkCudaErrors(cudaMallocPitch(&devSource, &pitch, image.width * sizeof(unsigned char), image.height));
    checkCudaErrors(cudaMallocPitch(&devDest, &pitch, image.width * sizeof(unsigned char), image.height));
    checkCudaErrors(cudaMemcpy2D(devSource, pitch,
                                 image.data, image.width * sizeof(unsigned char),
                                 image.width * sizeof(unsigned char), image.height, cudaMemcpyHostToDevice));

    dim3 block(32, 16);
    dim3 grid((image.width + block.x / 2 - 1) / block.x / 4, (image.height + block.y / 2 - 1) / block.y);

    cudaEventRecord(start);
    filterOperatorRGB<<<grid, block>>>(devFilter, devSource, devDest, pitch, image.width, image.height);
    cudaEventRecord(stop);

    checkCudaErrors(cudaMemcpy2D(image.data, image.width * sizeof(unsigned char), devDest, pitch,
                                 image.width * sizeof(unsigned char), image.height, cudaMemcpyDeviceToHost));

    cudaEventSynchronize(stop);
    float milliseconds = 0;
    cudaEventElapsedTime(&milliseconds, start, stop);

    image.data = removeImageBorderRGB(image.data, image.height, image.width);
    image.width -= 6;
    image.height -= 2;

    image.width /= 3;

    checkCudaErrors(cudaFree(devSource));
    checkCudaErrors(cudaFree(devDest));
    checkCudaErrors(cudaEventDestroy(start));
    checkCudaErrors(cudaEventDestroy(stop));

    return milliseconds;
}