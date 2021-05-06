#pragma once

#include <filters/filter.cuh>
#include <loader/loader.hpp>

class Image {
public:
    explicit Image(Loader::Image image);

public:
    Loader::Image getImage();
    void setFilter(Filter *filter);

public:
    virtual void applyFilter() = 0;
    virtual void edging() = 0;

protected:
    Filter *filter;
    Loader::Image image;
};