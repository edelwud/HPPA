#pragma once

#include <matrix/matrix.hpp>

#include <memory>

class VectorizedMatrix : public Matrix {
public:
    VectorizedMatrix(int rows, int columns);

public:
    void add(Matrix* matrix) override;
    void multiply(Matrix* matrix) override;
    void print() override;
};