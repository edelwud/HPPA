#pragma once

#include <matrix/matrix.hpp>

class MatrixCPU : public Matrix {
public:
    explicit MatrixCPU(long long n, long long m);

public:
    void process() override;
    void initialize() override;
};