#pragma once

#include <vector>

#include <matrix/matrix.hpp>
#include <matrix/standard_matrix.hpp>
#include <matrix/factory/matrix.hpp>

class StandardMatrixFactory : public MatrixFactory {
public:
    std::vector<Matrix *> create(int quantity, int rows, int columns) override {
        std::vector<Matrix *> result;
        result.reserve(quantity);
        for (int i = 0; i < quantity; i++) {
            result.push_back(new StandardMatrix(rows, columns));
        }
        return result;
    };
};