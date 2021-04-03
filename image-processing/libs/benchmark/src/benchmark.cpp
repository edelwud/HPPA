#include <chrono>

#include <benchmark/benchmark.hpp>

double Benchmark::executionTime(std::function<void()> handler) {
  using namespace std::chrono;
  auto start = high_resolution_clock::now();
  handler();
  auto end = high_resolution_clock::now();
  return (double)(end - start).count() / 1000000;
}
