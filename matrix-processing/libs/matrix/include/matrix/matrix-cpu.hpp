#pragma once

#include <matrix/matrix.hpp>

struct Transformation {
    short x1, x2, x3, x4;
};

class MatrixCPU : public Matrix {
public:
    explicit MatrixCPU(int n, int m);

public:
    void process() override;
    void initialize() override;
};