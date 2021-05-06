#pragma once

#include <map>

__global__ void filterOperator(std::map<int, int> &filter, short *devSource, short *devDest, size_t pitch, int width, int height);