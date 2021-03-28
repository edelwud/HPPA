#include <matrix.hpp>

#include <iostream>
#include <iomanip>

Matrix::Matrix(int n, int m) {
    rows = n;
    columns = m;
    size = columns*rows;
    matrix = new unsigned char[size];
}

int Matrix::getRows() const {
    return rows;
}

void Matrix::setRows(int n) {
    rows = n;
}

int Matrix::getColumns() const {
    return columns;
}

void Matrix::setColumns(int m) {
    columns = m;
}

Matrix::~Matrix() {
    delete[] matrix;
}

void Matrix::print(unsigned char* matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(4) << (int)matrix[i*m + j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Matrix::print() {
    print(matrix, rows, columns);
}

bool Matrix::operator==(Matrix& matrixObj) {
    for (int i = 0; i < matrixObj.getRows(); i++) {
        for (int j = 0; j < matrixObj.getColumns(); j++) {
            if (matrix[i*columns+j] != matrixObj.matrix[i*columns+j]) {
                return false;
            }
        }
    }
    return true;
}
