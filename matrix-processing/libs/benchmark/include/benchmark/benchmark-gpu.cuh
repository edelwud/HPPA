#pragma once

#include <cuda.h>
#include <cuda_runtime.h>

class BenchmarkGPU {
public:
    static void Start() {
        cudaEventCreate(&start);
        cudaEventCreate(&stop);

        cudaEventRecord(start);
        cudaEventRecord(stop);
    }
    static float End() {
        cudaEventRecord(stop);
        cudaEventSynchronize(stop);

        float milliseconds = 0;
        cudaEventElapsedTime(&milliseconds, start, stop);

        return milliseconds;
    }

private:
    static cudaEvent_t start, stop;
};