#pragma once

#define MATRIX_MIN_ELEMENT 1
#define MATRIX_MAX_ELEMENT 10

#include <memory>

class Matrix {
public:
    Matrix(int rows, int columns) : rows(rows), columns(columns) {}
    Matrix(const Matrix&);
    virtual ~Matrix();

public:
    virtual void add(Matrix* matrix) = 0;
    virtual void multiply(Matrix* matrix) = 0;
    virtual void print() = 0;
    virtual Matrix* clone() = 0;
    void fill(int value);

public:
    bool operator==(Matrix const& matrix) const;

protected:
    static void free(double **space, int rows, int columns);
    static void fill(double **space, int rows, int columns);
    static void fill(double **space, int rows, int columns, double value);
    static double** allocate(int rows, int columns);
    static double getRandomDouble(int min, int max);

public:
    int getRows() const;
    void setRows(double rows);

    int getColumns() const;
    void setColumns(double columns);

    double** getSpace() const;
    void setSpace(double **space);

protected:
    double **space;
    int columns;
    int rows;
};