#pragma once

#include <filters/filter.cuh>
#include <loader/loader.hpp>

void launchGrayscale(Filter *filter, Loader::Image image);
