#include <image-rgb-cpu.hpp>

#include <stdexcept>
#include <utils/helpers/helper_border_rgb.hpp>

ImageRGBCpu::ImageRGBCpu(Loader::Image image) : Image(image) {}

unsigned char ImageRGBCpu::fixIntensity(int intensity) {
    if (intensity > 255)
        return 255;

    if (intensity < 0)
        return 0;

    return (unsigned char) intensity;
}

void ImageRGBCpu::applyFilter() {
    if (!filter)
        throw std::runtime_error("image: filter is not assign");

    image.width *= 3;

    image.data = addImageBorderRGB(image.data, image.height, image.width);

    image.height+=2;
    image.width+=6;

    auto *newData = new unsigned char[image.width * image.height];

    for (int i = 1; i < image.height-1; ++i) {
        for (int n = 3; n < image.width-3; n += 3) {
            int r = 0;
            int g = 0;
            int b = 0;

            unsigned char *data = image.data + i * image.width + n;
            for (int l = -1, k = 0; k < 3; l++, k++) {
                for (int j = -1, m = 0; m < 3; j++, m++) {
                    int index = l * image.width + j*3;
                    r += data[index] * filter[k * 3 + m] / 9;
                    g += data[index + 1] * filter[k * 3 + m] / 9;
                    b += data[index + 2] * filter[k * 3 + m] / 9;
                }
            }

            newData[i * image.width + n] = fixIntensity(r);
            newData[i * image.width + n + 1] = fixIntensity(g);
            newData[i * image.width + n + 2] = fixIntensity(b);
        }
    }

    image.data = removeImageBorderRGB(newData, image.height, image.width);

    image.width /= 3;
    image.height -= 2;
    image.width -= 2;
}
