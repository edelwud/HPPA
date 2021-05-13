#pragma once

#include <image/image.hpp>

class ImageRGBCpu : public Image {
public:
    explicit ImageRGBCpu(Loader::Image image);

public:
    void applyFilter() override;
};