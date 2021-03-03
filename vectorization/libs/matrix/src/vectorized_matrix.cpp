#include <matrix/vectorized_matrix.hpp>

#include <iostream>
#include <iomanip>
#include <immintrin.h>

VectorizedMatrix::VectorizedMatrix(int rows, int columns) : Matrix(rows, columns) {
    space = allocate(rows, columns);
    fill(space, rows, columns, 10);
}

void VectorizedMatrix::add(Matrix *matrix) {
    auto result = allocate(rows, columns);
    for (int i = 0; i < rows; i++) {
        auto resultSpace = result[i];
        auto distSpace = matrix->getSpace()[i];
        auto hostSpace = space[i];
        for (int j = 0; j < columns; j+=4) {
            auto hostValue = _mm256_loadu_pd(hostSpace+j);
            auto distValue = _mm256_loadu_pd(distSpace+j);
            auto newValue = _mm256_fmadd_pd(hostValue, distValue, _mm256_loadu_pd(resultSpace+j));
            _mm256_storeu_pd(resultSpace+j, newValue);
        }
    }
    free(space, rows, columns);
    space = result;
}

void VectorizedMatrix::multiply(Matrix *matrix) {
    if (columns != matrix->getRows()) {
        throw std::runtime_error("cannot multiply matrix");
    }

    auto distSpace = matrix->getSpace();
    auto distColumns = matrix->getColumns();
    auto result = allocate(rows, distColumns+4);

    for(int i = 0; i < rows; i++) {
        auto *resultSpace = (double *)result[i];
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
    free(space, rows, columns);
    columns = distColumns;
    space = result;
}

void VectorizedMatrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << std::setprecision(3) << std::setw(5) << space[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

Matrix *VectorizedMatrix::clone() {
    return new VectorizedMatrix(*this);
}
