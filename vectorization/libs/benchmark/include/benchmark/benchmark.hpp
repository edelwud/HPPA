#pragma once

#include <functional>

class Benchmark {
public:
    static double getExecutionTime(std::function<void(void)> handler);
};