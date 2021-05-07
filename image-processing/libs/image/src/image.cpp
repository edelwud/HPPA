#include <image.hpp>

Image::Image(Loader::Image image) : image(image) {}

void Image::setFilter(char *filter_) {
    filter = filter_;
}

Loader::Image Image::getImage() {
    return image;
}