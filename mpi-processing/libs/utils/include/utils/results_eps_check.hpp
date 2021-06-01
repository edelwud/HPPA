#pragma once

#include <iostream>
#include <iomanip>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <cassert>
#include <cmath>

template<typename T>
void checkResultsEps(const T* const ref, const T* const gpu, size_t numElem, double eps1, double eps2) {
    assert(eps1 >= 0 && eps2 >= 0);
    unsigned long long totalDiff = 0;
    unsigned numSmallDifferences = 0;
    for (size_t i = 0; i < numElem; ++i) {
        //subtract smaller from larger in case of unsigned types
        T smaller = std::min(ref[i], gpu[i]);
        T larger = std::max(ref[i], gpu[i]);
        T diff = larger - smaller;
        if (diff > 0 && diff <= eps1) {
            numSmallDifferences++;
        }
        else if (diff > eps1) {
            std::cerr << "Difference at pos " << +i << " exceeds tolerance of " << eps1 << std::endl;
            std::cerr << "Reference: " << std::setprecision(17) << +ref[i] <<
                         "\nGPU      : " << +gpu[i] << std::endl;
            exit(1);
        }
        totalDiff += diff * diff;
    }
    double percentSmallDifferences = (double)numSmallDifferences / (double)numElem;
    if (percentSmallDifferences > eps2) {
        std::cerr << "Total percentage of non-zero pixel difference between the two images exceeds " << 100.0 * eps2 << "%" << std::endl;
        std::cerr << "Percentage of non-zero pixel differences: " << 100.0 * percentSmallDifferences << "%" << std::endl;
        exit(1);
    }
}