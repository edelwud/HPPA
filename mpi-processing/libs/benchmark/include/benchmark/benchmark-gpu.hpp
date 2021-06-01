#pragma once

#include <functional>

class BenchmarkGPU {
public:
    static double executionTime(std::function<void()> handler);
};