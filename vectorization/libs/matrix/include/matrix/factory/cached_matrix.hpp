#pragma once

#include <vector>

#include <matrix/matrix.hpp>
#include <matrix/cached_matrix.hpp>
#include <matrix/factory/matrix.hpp>

class CachedMatrixFactory : public MatrixFactory {
public:
    std::vector<Matrix *> create(int quantity, int rows, int columns) override {
        std::vector<Matrix *> result;
        result.reserve(quantity);
        for (int i = 0; i < quantity; i++) {
            result.push_back(new CachedMatrix(rows, columns));
        }
        return result;
    };
};