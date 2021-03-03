#pragma once

#include <matrix/matrix.hpp>
#include <matrix/vectorized_matrix.hpp>

#include <cmath>
#include <vector>

#define TOTAL_L3_MEMORY 8*1024*1024

#define BLOCK_MEMORY(memory) \
    int(memory/3)

#define TYPE_BLOCK_SIZE(memory, type) \
    int(BLOCK_MEMORY(memory)/sizeof(type))

#define TYPE_MATRIX_SIZE(memory, type) \
    int(sqrt(TYPE_BLOCK_SIZE(memory, type)))

#define MATRIX_BLOCK_SIDE TYPE_MATRIX_SIZE(TOTAL_L3_MEMORY, double)

struct MatrixBlock {
    int offsetRows, offsetColumns;
    Matrix *matrix;
};

class CachedMatrix : public Matrix {
public:
    CachedMatrix(int rows, int columns);

public:
    void multiply(Matrix* matrix) override;
    void add(Matrix* matrix) override;
    void print() override;
    Matrix* clone() override;

private:
    MatrixBlock** blocks();
    void emplace(Matrix* matrix, int offsetRows, int offsetColumns);
    int getBlocksRows();
    int getBlocksColumns();
};