#include <image.hpp>

#include <kernels/launcher-grayscale.cuh>

#include <stdexcept>

Image::Image(Loader::Image image) : image(image) {

}

void Image::setFilter(std::map<int, int> &filter_) {
    filter = filter_;
}

Loader::Image Image::getImage() {
    return image;
}