#include <image-rgb.hpp>

#include <kernels/launcher-rgb.cuh>

#include <stdexcept>
#include <iostream>

ImageRGB::ImageRGB(Loader::Image image) : Image(image) {}

double ImageRGB::applyFilter() {

    if (!filter)
        throw std::runtime_error("image: filter is not assign");

    return launchRGB(filter, image);
}
