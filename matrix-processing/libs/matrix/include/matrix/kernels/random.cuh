#pragma once

void launchRandom(unsigned char* devMemory, int rows, int columns);
__global__ void random(unsigned char* devMemory);
