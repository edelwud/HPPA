#include <laplace-filter.cuh>

LaplaceFilter::LaplaceFilter() : Filter(3, 3, LAPLACE_FILTER_MASK) {}