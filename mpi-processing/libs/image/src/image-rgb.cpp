#include <image-rgb.hpp>

#include <kernels/launcher-rgb.cuh>

#include <stdexcept>
#include <iostream>

ImageRGB::ImageRGB(Loader::Image image) : Image(image) {}

void ImageRGB::applyFilter() {
    if (!filter)
        throw std::runtime_error("image: filter is not assign");

    float milliseconds = launchRGB(filter, image);
    std::cout << "CUDA events benchmark: " << milliseconds << std::endl;
}
