#include <standard_matrix.hpp>

#include <iomanip>
#include <iostream>
#include <stdexcept>

StandardMatrix::StandardMatrix(int rows, int columns) : Matrix(rows, columns) {
    allocate();
    fill();
}

StandardMatrix::~StandardMatrix() {
    for (int i = 0; i < rows; i++) {
        delete[] space[i];
    }
    delete[] space;
}

void StandardMatrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << std::setprecision(3) << std::setw(5) << space[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

std::unique_ptr<Matrix> StandardMatrix::multiply(Matrix& matrix) {
    if (columns != matrix.getRows()) {
        throw std::runtime_error("cannot multiply matrix");
    }

    auto result = std::make_unique<StandardMatrix>(rows, matrix.getColumns());

    auto resultSpace = result->space;
    auto distSpace = matrix.getSpace();
    auto mColumns = matrix.getColumns();

#pragma clang loop vectorize(enable) interleave(enable)
    for(int i = 0; i < rows; i++)
#pragma clang loop vectorize(enable) interleave(enable)
        for(int j = 0; j < mColumns; j++)
#pragma clang loop vectorize(enable) interleave(enable)
            for(int k = 0; k < columns; k++) {
                result->space[i][j] += space[i][k] * distSpace[k][j];
            }

    return result;
}
std::unique_ptr<Matrix> StandardMatrix::add(std::unique_ptr<Matrix> matrix) {
    auto result = std::make_unique<StandardMatrix>(rows, columns);
    auto matrixSpace = matrix->getSpace();
#pragma clang loop vectorize(enable) interleave(enable)
#pragma clang loop vectorize_predicate(enable)
    for (int i = 0; i < rows; i++) {
#pragma clang loop vectorize(enable) interleave(enable)
        for (int j = 0; j < columns; j++) {
            result->space[i][j] = space[i][j] + matrixSpace[i][j];
        }
    }
    return result;
}
