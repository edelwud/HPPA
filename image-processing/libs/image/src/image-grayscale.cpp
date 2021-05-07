#include <image-grayscale.hpp>

#include <kernels/launcher-grayscale.cuh>

#include <stdexcept>
#include <iostream>

ImageGrayscale::ImageGrayscale(Loader::Image image) : Image(image) {}

void ImageGrayscale::applyFilter() {
    if (!filter)
        throw std::runtime_error("image: filter is not assign");

    float milliseconds = launchGrayscale(filter, image);
    std::cout << "CUDA events benchmark: " << milliseconds << std::endl;
}
