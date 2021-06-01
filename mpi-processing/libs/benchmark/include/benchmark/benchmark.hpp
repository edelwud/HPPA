#pragma once

#include <functional>

class Benchmark {
public:
    static double executionTime(std::function<void()> handler);
};
