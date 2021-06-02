#pragma once

#include <image/image.hpp>

class ImageRGBCpu : public Image {
public:
    explicit ImageRGBCpu(Loader::Image image);
    unsigned char fixIntensity(int intensity);
public:
    double applyFilter() override;
};
