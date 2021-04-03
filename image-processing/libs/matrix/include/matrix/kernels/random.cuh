#pragma once

void launchRandom(unsigned char *devMemory, long long rows, long long columns);
__global__ void random(unsigned char *devMemory);
