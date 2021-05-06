#pragma once

#include <map>
#include <loader/loader.hpp>

class Image {
public:
    explicit Image(Loader::Image image);

public:
    Loader::Image getImage();
    void setFilter(std::map<int, int> &filter);

public:
    virtual void applyFilter() = 0;

protected:
    std::map<int, int> filter;
    Loader::Image image;
};