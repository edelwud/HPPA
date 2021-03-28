#pragma once

#include <matrix/matrix.hpp>

class MatrixGPU : public Matrix {
public:
    explicit MatrixGPU(int n, int m);
    ~MatrixGPU();

public:
    void process() override;
    void initialize() override;

private:
    char* devSource;
    char* devDest;
};