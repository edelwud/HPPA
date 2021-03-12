#include <iostream>

#include <cache/cache.hpp>
#include <benchmark/benchmark.hpp>

int main() {
  int* array = AllocArray();

  for (int i = 2; i <= Nmax; i++) {
    FillArray(array, i);

    auto time = Benchmark::executionTime([array](){
      for (int j = 0, t = 0; j < ARRAY_SIZE; j++) {
        t = array[t];
      }
    });
    std::cout << "N: " << i << "; time: " << time << std::endl;
  }

  delete[] array;
  return 0;
}
