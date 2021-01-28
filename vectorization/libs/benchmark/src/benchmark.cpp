#include <benchmark.hpp>

#include <chrono>

double Benchmark::getExecutionTime(std::function<void(void)> handler) {
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    handler();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    return duration_cast<duration<double>>(t2 - t1).count();
}
