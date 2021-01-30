#include <benchmark.hpp>

#include <chrono>

using namespace std::chrono;

double Benchmark::getExecutionTime(std::function<void(void)> handler) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    handler();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    return duration_cast<duration<double>>(t2 - t1).count();
}

double Benchmark::executeForSeveralTimes(int times, std::function<void(void)> handler) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i = 0; i < times; i++) handler();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    return duration_cast<duration<double>>(t2 - t1).count();
}
