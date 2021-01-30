#pragma once

#include <matrix/matrix.hpp>

#include <memory>

class VectorizedMatrix : public Matrix {
public:
    VectorizedMatrix(int rows, int columns);

public:
    std::unique_ptr<Matrix> add(std::unique_ptr<Matrix> matrix) override;
    std::unique_ptr<Matrix> multiply(Matrix& matrix) override;
    void print() override;
};