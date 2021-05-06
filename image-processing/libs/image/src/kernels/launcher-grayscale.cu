#include <kernels/launcher-grayscale.cuh>

#include <filters/kernels/filter-operator.cuh>
#include <utils/error_check.hpp>
#include <utils/helpers/helper_border.hpp>

float launchGrayscale(std::map<int, int> &filter, Loader::Image &image) {

    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    image.data = addImageBorder(image.data, image.height, image.width);
    image.width += 2;
    image.height += 2;

    short *devSource;
    short *devDest;
    size_t pitch;

    checkCudaErrors(cudaMallocPitch(&devSource, &pitch, image.width * sizeof(short), image.height));
    checkCudaErrors(cudaMallocPitch(&devDest, &pitch, image.width * sizeof(short), image.height));
    checkCudaErrors(cudaMemcpy2D(devSource, pitch,
                                 image.data, image.width * sizeof(short),
                                 image.width * sizeof(short), image.height, cudaMemcpyHostToDevice));

    dim3 block(32, 16);
    dim3 grid((image.width + block.x / 2 - 1) / block.x / 2, (image.height + block.y / 2 - 1) / block.y / 2);

    cudaEventRecord(start);
    filterOperator<<<grid, block>>>(filter, devSource, devDest, pitch, image.width, image.height);
    cudaEventRecord(stop);

    checkCudaErrors(cudaMemcpy2D(image.data, image.width * sizeof(short), devSource, pitch,
                                 image.width*sizeof(short), image.height, cudaMemcpyDeviceToHost));

    cudaEventSynchronize(stop);
    float milliseconds = 0;
    cudaEventElapsedTime(&milliseconds, start, stop);

    image.data = removeImageBorder(image.data, image.height, image.width);
    image.width -= 2;
    image.height -= 2;

    checkCudaErrors(cudaFree(devSource));
    checkCudaErrors(cudaFree(devDest));
    checkCudaErrors(cudaEventDestroy(start));
    checkCudaErrors(cudaEventDestroy(stop));

    return milliseconds;
}