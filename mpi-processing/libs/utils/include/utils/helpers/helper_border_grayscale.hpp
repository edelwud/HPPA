#pragma once

#include <cstring>

unsigned char  *addImageBorderGrayscale(unsigned char *sourceImage, size_t height, size_t width);
unsigned char  *removeImageBorderGrayscale(unsigned char  *imageWithBorder, size_t borderedHeight, size_t borderedWidth);