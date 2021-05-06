#pragma once

#include <functional>

class Image {
public:
    explicit Image(unsigned char *data, unsigned int w, unsigned int h);

public:
    void laplaceOperator();

private:
    unsigned char *data;
    unsigned int width;
    unsigned int height;
};