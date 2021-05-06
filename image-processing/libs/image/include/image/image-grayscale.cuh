#pragma once

#include <image/image.cuh>

class ImageGrayscale : public Image {
public:
    explicit ImageGrayscale(Loader::Image image);

public:
    void applyFilter();
};