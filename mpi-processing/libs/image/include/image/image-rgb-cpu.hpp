#pragma once

#include <image/image.hpp>

class ImageRGBCpu : public Image {
public:
    explicit ImageRGBCpu(Loader::Image image);
    unsigned char fixIntensity(int intensity);
public:
    void applyFilter() override;
};