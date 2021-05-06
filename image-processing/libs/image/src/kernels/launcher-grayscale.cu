#include <kernels/launcher-grayscale.cuh>

#include <utils/error_check.hpp>

void launchGrayscale(Filter *filter, Loader::Image image) {
    short * data;
    size_t pitch;

    checkCudaErrors(cudaMallocPitch(&data, &pitch, image.width, image.height));
    checkCudaErrors(cudaMemcpy2D(data, pitch, image.data, 0, image.width, image.height, cudaMemcpyHostToDevice));

}