#pragma once

#include <filters/filter.cuh>
#include <loader/loader.hpp>

class Image {
public:
    explicit Image(Loader::Image image);

public:
    Loader::Image getImage();
    void setFilter(Filter *filter);
    void applyFilter();

private:
    Filter *filter = nullptr;
    Loader::Image image;
};