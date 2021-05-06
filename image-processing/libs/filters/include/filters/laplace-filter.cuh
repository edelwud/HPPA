#pragma once

#include <filter.cuh>

#define LAPLACE_FILTER_MASK {   \
        1,  1,  1,              \
        1, -8,  1,              \
        1,  1,  1               \
}

class LaplaceFilter : public Filter {
public:
    LaplaceFilter();
};