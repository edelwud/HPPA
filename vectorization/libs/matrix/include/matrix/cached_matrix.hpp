#pragma once

#include <matrix/matrix.hpp>
#include <matrix/vectorized_matrix.hpp>

#include <vector>

class CachedMatrix : public Matrix {
public:
    CachedMatrix(int rows, int columns);

public:
    void multiply(Matrix* matrix) override;
    void add(Matrix* matrix) override;
    void print() override;

private:
    VectorizedMatrix*** blocks();
    int getBlocksRows();
    int getBlocksColumns();
};