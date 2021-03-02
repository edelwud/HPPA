#include <iostream>
#include <iomanip>
#include <immintrin.h>

#include <matrix/cached_matrix.hpp>

CachedMatrix::CachedMatrix(int rows, int columns) : Matrix(rows, columns) {
    space = allocate(rows, columns);
    fill(space, rows, columns, 10);
}

void CachedMatrix::multiply(Matrix *matrix) {
    if (columns != matrix->getRows()) {
        throw std::runtime_error("cannot multiply matrix");
    }

    auto remoteMatrix = dynamic_cast<CachedMatrix*>(matrix);

    auto currentBlocks = blocks();
    auto remoteBlock = remoteMatrix->blocks();
}

void CachedMatrix::add(Matrix *matrix) {
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

void CachedMatrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << std::setprecision(3) << std::setw(5) << space[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

std::vector<VectorizedMatrix *> CachedMatrix::blocks() {
    int blocksRows = getBlocksRows();
    int blocksColumns = getBlocksColumns();

    auto*** blocks = new VectorizedMatrix**[blocksRows];
    for (int i = 0; i < blocksRows; i++) {
        blocks[i] = new VectorizedMatrix*[blocksColumns];
        for (int j = 0; j < blocksColumns; j++) {
            blocks[i][j] = new VectorizedMatrix();
        }
    }

    return std::vector<VectorizedMatrix *>();
}

int CachedMatrix::getBlocksRows() {
    return 0;
}

int CachedMatrix::getBlocksColumns() {
    return 0;
}
