#include <image-grayscale-cpu.hpp>

#include <stdexcept>

ImageGrayscaleCpu::ImageGrayscaleCpu(Loader::Image image) : Image(image) {}

void ImageGrayscaleCpu::applyFilter() {
    if (!filter)
        throw std::runtime_error("image: filter is not assign");


}
