#include <matrix/vectorized_matrix.hpp>

#include <iostream>
#include <iomanip>
#include <immintrin.h>

std::unique_ptr<Matrix> VectorizedMatrix::add(std::unique_ptr<Matrix> matrix) {
    auto result = std::make_unique<VectorizedMatrix>(rows, columns);
    auto matrixSpace = matrix->getSpace();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result->space[i][j] = space[i][j] + matrixSpace[i][j];
        }
    }
    return result;
}

std::unique_ptr<Matrix> VectorizedMatrix::multiply(Matrix &matrix) {
    if (columns != matrix.getRows()) {
        throw std::runtime_error("cannot multiply matrix");
    }

    auto result = std::make_unique<VectorizedMatrix>(rows, matrix.getColumns());

    auto distSpace = matrix.getSpace();
    auto distColumns = matrix.getColumns();

    for(int i = 0; i < rows; i++) {
        auto *resultSpace = (double *) result->space[i];
        for (int m = 0; m < columns; m += 4) {
            _mm256_storeu_pd(resultSpace + m, _mm256_setzero_pd());
        }
        for (int k = 0; k < columns; k++) {
            __m256d hostValue = _mm256_set1_pd(space[i][k]);
            for (int j = 0; j < distColumns; j += 4) {
                auto distValue = _mm256_loadu_pd(distSpace[k]+j);
                auto oldValue = _mm256_loadu_pd(resultSpace+j);
                auto newValue = _mm256_fmadd_pd(hostValue, distValue, oldValue);
                _mm256_storeu_pd(resultSpace+j, newValue);
            }
        }
    }
    return result;
}

void VectorizedMatrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << std::setprecision(3) << std::setw(5) << space[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
VectorizedMatrix::VectorizedMatrix(int rows, int columns) : Matrix(rows, columns) {
    allocate();
    fill();
}
