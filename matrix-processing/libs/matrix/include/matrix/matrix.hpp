#pragma once

class Matrix {
public:
    explicit Matrix(long long n, long long m);
    virtual ~Matrix();

public:
    virtual void process() = 0;
    virtual void initialize() = 0;

public:
    virtual void print();
    static void print(unsigned char* data, long long n, long long m);

public:
    bool operator==(Matrix& matrix);

public:
    long long getRows() const;
    void setRows(long long n);

    long long getColumns() const;
    void setColumns(long long m);

protected:
    long long rows;
    long long columns;
    long long size;
    unsigned char* matrix;
};