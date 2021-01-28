#include <matrix/matrix.hpp>

int Matrix::getRows() const {
    return rows;
}

void Matrix::setRows(double rows) {
    this->rows = rows;
}

int Matrix::getColumns() const {
    return columns;
}

void Matrix::setColumns(double columns) {
    this->columns = columns;
}

double **Matrix::getSpace() const {
    return space;
}

double Matrix::getRandomDouble(int min, int max) {
    return min + (double)(rand()) / ((double)(RAND_MAX/(max - min)));
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
