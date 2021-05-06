#include <image-grayscale.cuh>

#include <kernels/launcher-grayscale.cuh>
#include <utils/error_check.hpp>

#include <stdexcept>

ImageGrayscale::ImageGrayscale(Loader::Image image) : Image(image) {}

void ImageGrayscale::applyFilter() {
    if (!filter)
        throw std::runtime_error("image: filter is not assign");
}
