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

    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < matrix.getColumns(); ++j)
            for(int k = 0; k < columns; ++k) {
                result->space[i][j] += space[i][k] * matrix.getSpace()[k][j];
            }

    return result;
}
std::unique_ptr<Matrix> StandardMatrix::add(std::unique_ptr<Matrix> matrix) {
    auto result = std::make_unique<StandardMatrix>(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result->space[i][j] = space[i][j] + matrix->getSpace()[i][j];
        }
    }
    return result;
}
