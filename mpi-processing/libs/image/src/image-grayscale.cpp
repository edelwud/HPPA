#include <image-grayscale.hpp>

#include <kernels/launcher-grayscale.cuh>

#include <stdexcept>
#include <iostream>

ImageGrayscale::ImageGrayscale(Loader::Image image) : Image(image) {}

double ImageGrayscale::applyFilter() {
    if (!filter)
        throw std::runtime_error("image: filter is not assign");

    return launchGrayscale(filter, image);
}
