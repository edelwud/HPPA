#pragma once

#include <matrix/matrix.hpp>

class MatrixGPU : public Matrix {
public:
    explicit MatrixGPU(int n, int m);

public:
    void process() override;
    void initialize() override;
};