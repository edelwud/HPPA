#include <helpers/helper_border_rgb.hpp>

#include <stdexcept>

/**
 * height and width in bytes
 * @param sourceImage
 * @param height
 * @param width
 * @return
 */
unsigned char  *addImageBorderRGB(unsigned char *sourceImage, size_t height, size_t width) {
    if (height < 3 || width < 3) {
        throw std::runtime_error("invalid array sizes");
    }
    auto twoPixelBytes = 2*3;
    auto borderedHeight = height + twoPixelBytes;
    auto borderedWidth = width + twoPixelBytes;
    auto borderedSize = borderedHeight * borderedWidth;
    auto imageWithBorder = new unsigned char [borderedSize];
    memset(imageWithBorder, 0, borderedSize * sizeof(unsigned char));
    for (size_t i = 1; i < height - 1; ++i) {
        auto srcOffset = (i - 1) * width;
        memcpy(&imageWithBorder[i * borderedWidth + 3],
               sourceImage + srcOffset, width * sizeof(unsigned char ));
    }
    delete[] sourceImage;
    return imageWithBorder;
}

/**
 * height and width in bytes
 * @param imageWithBorder
 * @param borderedHeight
 * @param borderedWidth
 * @return
 */
unsigned char  *removeImageBorderRGB(unsigned char  *imageWithBorder, size_t borderedHeight, size_t borderedWidth) {
    if (borderedHeight < 6 || borderedWidth < 6) {
        throw std::runtime_error("invalid array sizes");
    }
    auto height = borderedHeight - 6;
    auto width = borderedWidth - 6;
    auto size = height * width;
    auto imageWithoutBorder = new unsigned char [size];
    for (size_t i = 0; i < height; ++i) {
        auto srcOffset = (i + 1) * borderedWidth + 3;
        memcpy(imageWithoutBorder + (i * width), imageWithBorder + srcOffset, width * sizeof(unsigned char ));
    }
    delete[] imageWithBorder;
    return imageWithoutBorder;
}
