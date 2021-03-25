#pragma once

#define MASK_SIZE 2

class Matrix {
public:
    explicit Matrix(int n, int m);
    virtual ~Matrix();

public:
    virtual void process() = 0;
    virtual void initialize() = 0;

public:
    void print();
    void print(int n, int m);

public:
    bool operator=(Matrix& matrix);

public:
    int getRows() const;
    void setRows(int n);

    int getColumns() const;
    void setColumns(int m);

protected:
    int rows;
    int columns;
    short* matrix;
};