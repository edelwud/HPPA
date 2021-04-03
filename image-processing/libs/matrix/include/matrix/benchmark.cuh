#pragma once

#include <matrix/matrix.hpp>

class MatrixGPU : public Matrix {
public:
  explicit MatrixGPU(long long n, long long m);

public:
  void process() override;
  void initialize() override;
};