#pragma once

#include <vector>

#include <matrix/matrix.hpp>

class MatrixFactory {
public:
    virtual std::vector<Matrix *> create(int quantity, int rows, int columns) = 0;
};