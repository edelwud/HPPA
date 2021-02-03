#include <matrix/matrix.hpp>

Matrix::~Matrix() {
    free(space, rows, columns);
}


Matrix::Matrix(const Matrix& matrix) {
    rows = matrix.rows;
    columns = matrix.columns;

    space = allocate(rows, columns);

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.columns; j++) {
            space[i][j] = matrix.space[i][j];
        }
    }
}

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

double** Matrix::allocate(int rows, int columns) {
    auto space = new double*[rows];
    for (int i = 0; i < rows; i++) {
        space[i] = new double[columns];
        for (int j = 0; j < columns; j++) {
            space[i][j] = 0;
        }
    }
    return space;
}

void Matrix::fill(double **space, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            space[i][j] = getRandomDouble(MATRIX_MIN_ELEMENT, MATRIX_MAX_ELEMENT);
        }
    }
}

void Matrix::free(double **space, int rows, int columns) {
    if (!space) {
        return;
    }
    for (int i = 0; i < rows; i++) {
        delete[] space[i];
    }
    delete[] space;
}

void Matrix::fill(double **space, int rows, int columns, double value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            space[i][j] = value;
        }
    }
}

bool Matrix::operator==(const Matrix &matrix) const {
    if (rows != matrix.rows || columns != matrix.columns) {
        return false;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (space[i][j] != matrix.space[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void Matrix::fill(int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            space[i][j] = value;
        }
    }
}
