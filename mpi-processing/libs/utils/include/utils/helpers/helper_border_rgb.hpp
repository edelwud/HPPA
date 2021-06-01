#pragma once

#include <cstring>

unsigned char  *addImageBorderRGB(unsigned char *sourceImage, size_t height, size_t width);
unsigned char  *removeImageBorderRGB(unsigned char  *imageWithBorder, size_t borderedHeight, size_t borderedWidth);