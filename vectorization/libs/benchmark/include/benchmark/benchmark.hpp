#pragma once

#include <functional>

class Benchmark {
public:
    static double getExecutionTime(std::function<void(void)> handler);
    static double executeForSeveralTimes(int times, std::function<void(void)> handler);
};