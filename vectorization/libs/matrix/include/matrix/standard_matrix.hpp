#pragma once

#include <matrix/matrix.hpp>

class StandardMatrix : public Matrix {
public:
    StandardMatrix(int rows, int columns);
    ~StandardMatrix();

public:
    std::unique_ptr<Matrix> multiply(Matrix& matrix) override;
    std::unique_ptr<Matrix> add(std::unique_ptr<Matrix> matrix) override;
    void print() override;
};