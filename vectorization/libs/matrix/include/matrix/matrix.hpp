#pragma once

#define MATRIX_MIN_ELEMENT 1
#define MATRIX_MAX_ELEMENT 10

#include <memory>

class Matrix {
public:
    Matrix(int rows, int columns) : rows(rows), columns(columns) {}

    virtual std::unique_ptr<Matrix> add(std::unique_ptr<Matrix> matrix) = 0;
    virtual std::unique_ptr<Matrix> multiply(Matrix& matrix) = 0;
    virtual void print() = 0;

protected:
    void fill();
    void allocate();
    double getRandomDouble(int min, int max);

public:
    int getRows() const;
    void setRows(double rows);

    int getColumns() const;
    void setColumns(double columns);

    double** getSpace() const;

protected:
    double **space;
    int columns;
    int rows;
};