#pragma once

#include <image/image.hpp>

class ImageGrayscale : public Image {
public:
    explicit ImageGrayscale(Loader::Image image);

public:
    void applyFilter();
};