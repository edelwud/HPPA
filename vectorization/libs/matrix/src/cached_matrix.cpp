#include <iostream>
#include <iomanip>
#include <immintrin.h>
#include <cmath>

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
    auto currentBlocksRows = getBlocksRows();
    auto currentBlocksColumns = getBlocksColumns();

    auto remoteBlocks = remoteMatrix->blocks();
    auto remoteBlocksRows = remoteMatrix->getBlocksRows();
    auto remoteBlocksColumns = remoteMatrix->getBlocksColumns();

    fill(0);

    for(int i = 0; i < currentBlocksRows; i++) {
        auto currentBlocksRow = currentBlocks[i];
        for (int k = 0; k < currentBlocksColumns; k++) {
            auto currentBlock = currentBlocksRow[k];
            auto remoteBlocksRow = remoteBlocks[k];
            for (int j = 0; j < remoteBlocksColumns; j++) {
                auto currentBlocksMatrix = currentBlock.matrix->clone();
                auto remoteBlocksMatrix = remoteBlocksRow[j].matrix;
                currentBlocksMatrix->multiply(remoteBlocksMatrix);

                int offsetRows = i*MATRIX_BLOCK_SIDE;
                int offsetColumns = j*MATRIX_BLOCK_SIDE;

                emplace(currentBlocksMatrix, offsetRows, offsetColumns);
                delete currentBlocksMatrix;
            }
        }
    }
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

MatrixBlock** CachedMatrix::blocks() {
    int blocksRows = getBlocksRows();
    int blocksColumns = getBlocksColumns();

    auto** blocks = new MatrixBlock*[blocksRows];
    for (int i = 0; i < blocksRows; i++) {
        blocks[i] = new MatrixBlock[blocksColumns];
        for (int j = 0; j < blocksColumns; j++) {
            int totalRows = std::min(rows-i*MATRIX_BLOCK_SIDE, MATRIX_BLOCK_SIDE);
            int totalColumns = std::min(columns-j*MATRIX_BLOCK_SIDE, MATRIX_BLOCK_SIDE);

            auto matrix = new VectorizedMatrix(totalRows, totalColumns);
            auto matrixSpace = matrix->getSpace();

            int offsetRows = j*MATRIX_BLOCK_SIDE;
            int offsetColumns = i*MATRIX_BLOCK_SIDE;

            for (int k = offsetRows, s = 0; k < offsetRows+totalRows; k++, s++) {
                for (int m = offsetColumns, t = 0; m < offsetColumns+totalColumns; m++, t++) {
                    matrixSpace[s][t] = space[k][m];
                }
            }

            blocks[i][j] = {
                .offsetRows = offsetRows,
                .offsetColumns = offsetColumns,
                .matrix = matrix
            };
        }
    }

    return blocks;
}

int CachedMatrix::getBlocksRows() {
    return ceil(double(rows)/MATRIX_BLOCK_SIDE);
}

int CachedMatrix::getBlocksColumns() {
    return ceil(double(columns)/MATRIX_BLOCK_SIDE);
}

void CachedMatrix::emplace(Matrix *matrix, int offsetRows, int offsetColumns) {
    auto matrixSpace = matrix->getSpace();

    auto totalRows = std::min(rows, offsetRows+MATRIX_BLOCK_SIDE);
    auto totalColumns = std::min(columns, offsetColumns+MATRIX_BLOCK_SIDE);

    for (int i = offsetRows, k = 0; i < totalRows; i++, k++) {
        for (int j = offsetColumns, m = 0; j < totalColumns; j++, m++) {
            space[i][j] += matrixSpace[k][m];
        }
    }
}

Matrix *CachedMatrix::clone() {
    return new CachedMatrix(*this);
}
