#pragma once

#include <image/image.hpp>

class ImageRGB : public Image {
public:
    explicit ImageRGB(Loader::Image image);

public:
    double applyFilter() override;
};
