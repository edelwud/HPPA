#include <loader.hpp>

#include <utils/helpers/helper_image.hpp>

Loader::Image Loader::loadImage(const std::string &path, unsigned int channels) {
    unsigned int width = 0;
    unsigned int height = 0;
    unsigned char *data = nullptr;

    __loadPPM(path.c_str(), &data, &width, &height, &channels);

    return {data, width, height};
}

void Loader::saveImage(Image image, const std::string &path, unsigned int channels) {
    __savePPM(path.c_str(), image.data, image.width, image.height, channels);
}