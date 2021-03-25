#pragma once

#include <iostream>
#include <iomanip>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>

template<typename T>
void checkResultsExact(const T* const ref, const T* const gpu, size_t numElem) {
    //check that the GPU result matches the CPU result
    for (size_t i = 0; i < numElem; ++i) {
        if (ref[i] != gpu[i]) {
            std::cerr << "Difference at pos " << i << std::endl;
            //the + is magic to convert char to int without messing
            //with other types
            std::cerr << "Reference: " << std::setprecision(17) << +ref[i] <<
                      "\nGPU      : " << +gpu[i] << std::endl;
            exit(1);
        }
    }
}