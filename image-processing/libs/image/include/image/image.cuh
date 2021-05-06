#pragma once

#include <filters/filter.cuh>

class Image {
public:
    explicit Image(const unsigned char *data, int w, int h);

public:
    short * getData();
    void setFilter(Filter *filter);
    void applyFilter();

private:
    Filter *filter = nullptr;
    short *data;
    int width;
    int height;
};