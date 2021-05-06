#include <loader.hpp>

#include <utils/helpers/helper_image.hpp>

Loader::Image Loader::loadImage(const std::string& path, unsigned int channels) {
    unsigned int width = 0;
    unsigned int height = 0;
    unsigned char * data = nullptr;

    __loadPPM(path.c_str(), &data, &width, &height, &channels);

    auto image = new short [width * height];

    for (int i = 0; i < width * height; i++)
        image[i] = data[i];

    return { image, width, height };
}