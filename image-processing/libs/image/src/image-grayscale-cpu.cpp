#include <image-grayscale-cpu.hpp>

#include <stdexcept>

ImageGrayscaleCpu::ImageGrayscaleCpu(Loader::Image image) : Image(image) {}

void ImageGrayscaleCpu::applyFilter() {
    if (!filter)
        throw std::runtime_error("image: filter is not assign");

    auto *newData = new unsigned char[image.width * image.height];

    for (int i = 1; i < image.height - 1; ++i) {
        for (int n = 1; n < image.width - 1; ++n) {
            short result = 0;
            unsigned char *data = image.data + i * image.width + n;
            for (int l = -1, k = 0; k < 3; l++, k++) {
                for (int j = -1, m = 0; m < 3; j++, m++) {
                    int index = l * image.width + j;
                    result += data[index] * filter[k * 3 + m];
                }
            }

            result /= 9;
            if (result < 0)
                result = 0;
            if (result > 255)
                result = 255;

            result += 100;

            newData[i * image.width + n] = (char) result;
        }
    }

    image.data = newData;
}
