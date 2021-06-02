#pragma once

#include <image/image.hpp>

class ImageGrayscaleCpu : public Image {
public:
    explicit ImageGrayscaleCpu(Loader::Image image);

public:
    double applyFilter() override;
};
