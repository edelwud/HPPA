#pragma once

#include <matrix/matrix.hpp>

class StandardMatrix : public Matrix {
public:
    StandardMatrix(int rows, int columns);

public:
    void multiply(Matrix* matrix) override;
    void add(Matrix* matrix) override;
    void print() override;
};