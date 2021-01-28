#pragma once

#define MATRIX_MIN_ELEMENT 1
#define MATRIX_MAX_ELEMENT 10

#include <memory>

class Matrix {
public:
    Matrix(int rows, int columns);
    ~Matrix();

public:
    std::unique_ptr<Matrix> multiply(Matrix& matrix);
    void print();

private:
    void fill();
    void allocate();
    double getRandomDouble(int min, int max);

public:
    double getRows() const;
    void setRows(double rows);

    double getColumns() const;
    void setColumns(double columns);

private:
    double **space;
    int rows;
    int columns;
};