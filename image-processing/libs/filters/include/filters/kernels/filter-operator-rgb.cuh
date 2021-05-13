#pragma once

__global__ void filterOperatorRGB(const char *filter, unsigned char *devSource,
                                        unsigned char *devDest, size_t pitch, int width, int height);