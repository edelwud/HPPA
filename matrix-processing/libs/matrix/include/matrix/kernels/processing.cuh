#pragma once

void launchProcessing(unsigned char*, unsigned char*, int rows, int columns);
__global__ void processing(const unsigned char*, unsigned char*, int rows, int columns);