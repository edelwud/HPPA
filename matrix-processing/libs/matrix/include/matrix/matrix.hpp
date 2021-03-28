#pragma once

class Matrix {
public:
    explicit Matrix(int n, int m);
    virtual ~Matrix();

public:
    virtual void process() = 0;
    virtual void initialize() = 0;

public:
    virtual void print();
    static void print(unsigned char* data, int n, int m);

public:
    bool operator==(Matrix& matrix);

public:
    int getRows() const;
    void setRows(int n);

    int getColumns() const;
    void setColumns(int m);

protected:
    int rows;
    int columns;
    int size;
    unsigned char* matrix;
};