#pragma once

#include <map>

__global__ void filterOperator(const char *filter, unsigned char *devSource,
                               unsigned char *devDest, size_t pitch, int width, int height);