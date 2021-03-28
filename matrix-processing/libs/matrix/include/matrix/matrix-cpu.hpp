#pragma once

#include <matrix/matrix.hpp>

class MatrixCPU : public Matrix {
public:
    explicit MatrixCPU(int n, int m);

public:
    void process() override;
    void initialize() override;
};