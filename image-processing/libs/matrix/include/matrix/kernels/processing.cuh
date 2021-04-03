#pragma once

void launchProcessing(unsigned char *, unsigned char *, unsigned char *,
                      long long rows, long long columns);
__global__ void processing(const unsigned char *, unsigned char *,
                           long long rows, long long columns);