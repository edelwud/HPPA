#include "matrix.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>

Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns) {
    allocate();
    fill();
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] space[i];
    }
    delete[] space;
}

double Matrix::getRows() const {
    return rows;
}

void Matrix::setRows(double rows) {
    this->rows = rows;
}

double Matrix::getColumns() const {
    return columns;
}

void Matrix::setColumns(double columns) {
    this->columns = columns;
}

void Matrix::allocate() {
    space = new double*[rows];
    for (int i = 0; i < rows; i++) {
        space[i] = new double[columns];
    }
}

void Matrix::fill() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            space[i][j] = getRandomDouble(MATRIX_MIN_ELEMENT, MATRIX_MAX_ELEMENT);
        }
    }
}

void Matrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << std::setprecision(3) << std::setw(5) << space[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

double Matrix::getRandomDouble(int min, int max) {
    return min + (double)(rand()) / ((double)(RAND_MAX/(max - min)));
}

std::unique_ptr<Matrix> Matrix::multiply(Matrix& matrix) {
    if (columns != matrix.rows) {
        throw std::runtime_error("cannot multiply matrix");
    }

    auto result = std::make_unique<Matrix>(rows, matrix.columns);

    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < matrix.columns; ++j)
            for(int k = 0; k < columns; ++k) {
                result->space[i][j] += space[i][k] * matrix.space[k][j];
            }

    return result;
}
