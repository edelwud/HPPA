#include <image.cuh>

#include <stdexcept>

Image::Image(const unsigned char *data_, int w, int h) : width(w), height(h) {
    for (int i = 0; i < width * height; i++) {
        data[i] = data_[i];
    }
}

void Image::setFilter(Filter *filter_) {
    this->filter = filter_;
}

short * Image::getData() {
    return data;
}

void Image::applyFilter() {
    if (!filter)
        throw std::runtime_error("image: filter is not assign");
}
