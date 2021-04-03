#include <matrix-cpu.hpp>

#include <cmath>
#include <random>

MatrixCPU::MatrixCPU(long long n, long long m) : Matrix(n, m) {}

void MatrixCPU::process() {
  long long n = rows * 2;
  long long m = columns / 2;
  auto *result = new unsigned char[rows * columns];

  for (long long i = 0; i < rows; i++) {
    auto rowsOffset = i * columns;
    auto doubleRowsOffset = rowsOffset;
    for (long long j = 0; j < columns; j += 4) {
      if (j + 4 > columns)
        continue;
      auto startResultOffset = doubleRowsOffset + (long long)std::ceil(j / 2);
      result[startResultOffset] = matrix[rowsOffset + j + 2];
      result[startResultOffset + 1] = matrix[rowsOffset + j + 3];
      result[startResultOffset + m] = matrix[rowsOffset + j];
      result[startResultOffset + m + 1] = matrix[rowsOffset + j + 1];
    }
  }

  delete[] matrix;
  matrix = result;
  columns = m;
  rows = n;
}

void MatrixCPU::initialize() {
  std::default_random_engine generator;
  std::uniform_int_distribution<unsigned char> distribution(10, 100);

  for (long long i = 0; i < rows; i++) {
    for (long long j = 0; j < columns; j++) {
      matrix[i * columns + j] = distribution(generator);
    }
  }
}
