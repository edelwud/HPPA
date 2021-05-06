#pragma once

#include <string>

#define LOADER_ASSETS_PATH std::string("../../../../assets/")

namespace Loader {
    struct Image {
        short * data;
        unsigned int width;
        unsigned int height;
    };

    Image loadImage(const std::string& path, unsigned int channels);
}