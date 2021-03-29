#include <matrix.hpp>

#include <iostream>
#include <iomanip>

Matrix::Matrix(long long n, long long m) {
    rows = n;
    columns = m;
    size = columns*rows;
    matrix = new unsigned char[size];
}

long long Matrix::getRows() const {
    return rows;
}

void Matrix::setRows(long long n) {
    rows = n;
}

long long Matrix::getColumns() const {
    return columns;
}

void Matrix::setColumns(long long m) {
    columns = m;
}

Matrix::~Matrix() {
    delete[] matrix;
}

void Matrix::print(unsigned char* matrix, long long n, long long m) {
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            std::cout << std::setw(4) << (long long)matrix[i*m + j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Matrix::print() {
    print(matrix, rows, columns);
}

bool Matrix::operator==(Matrix& matrixObj) {
    for (long long i = 0; i < matrixObj.getRows(); i++) {
        for (long long j = 0; j < matrixObj.getColumns(); j++) {
            if (matrix[i*columns+j] != matrixObj.matrix[i*columns+j]) {
                return false;
            }
        }
    }
    return true;
}
