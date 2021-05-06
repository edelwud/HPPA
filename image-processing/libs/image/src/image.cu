#include <image.cuh>

#include <stdexcept>

Image::Image(Loader::Image image) : image(image) {}

void Image::setFilter(Filter *filter_) {
    this->filter = filter_;
}

Loader::Image Image::getImage() {
    return image;
}

void Image::applyFilter() {
    if (!filter)
        throw std::runtime_error("image: filter is not assign");
}
