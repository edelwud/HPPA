#include <matrix-cpu.hpp>

#include <cmath>
#include <random>

MatrixCPU::MatrixCPU(int n, int m) : Matrix(n, m) {
}

void MatrixCPU::process() {
    int n = rows*2;
    int m = columns/2;
    short* result = new short[rows * columns];

    for (int i = 0; i < rows; i++) {
        auto rowsOffset = i*columns;
        auto doubleRowsOffset = rowsOffset;
        for (int j = 0; j < columns; j += 4) {
            if (j + 4 > columns)
                continue;
            auto startResultOffset = doubleRowsOffset + (int)std::ceil(j/2);
            result[startResultOffset] = matrix[rowsOffset + j + 2];
            result[startResultOffset+1] = matrix[rowsOffset + j + 3];
            result[startResultOffset+m] = matrix[rowsOffset + j];
            result[startResultOffset+m+1] = matrix[rowsOffset + j + 1];
        }
    }

    delete[] matrix;
    matrix = result;
    columns = m;
    rows = n;
}

void MatrixCPU::initialize() {
    std::default_random_engine generator;
    std::uniform_int_distribution<short> distribution(10,100);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i*columns+j] = distribution(generator);
        }
    }
}
