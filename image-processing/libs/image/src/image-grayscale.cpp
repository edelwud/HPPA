#include <image-grayscale.hpp>

#include <kernels/launcher-grayscale.cuh>

#include <stdexcept>

ImageGrayscale::ImageGrayscale(Loader::Image image) : Image(image) {}

void ImageGrayscale::applyFilter() {
    if (!filter)
        throw std::runtime_error("image: filter is not assign");

    launchGrayscale(filter, image);
}
