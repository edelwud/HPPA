#pragma once

#include <map>
#include <loader/loader.hpp>

class Image {
public:
    explicit Image(Loader::Image image);

public:
    Loader::Image getImage();
    void setFilter(char *filter);

public:
    virtual double applyFilter() = 0;

protected:
    char *filter;
    Loader::Image image;
};
