#pragma once

#include <string>

#define LOADER_ASSETS_PATH std::string("../../../../assets/")

namespace Loader {
    struct Image {
        unsigned char * data;
        unsigned int width;
        unsigned int height;
    };

    Image loadImage(const std::string& path, unsigned int channels);
    void saveImage(Image image, const std::string& path, unsigned int channels);
}