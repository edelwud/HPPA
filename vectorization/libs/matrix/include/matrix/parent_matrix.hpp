#pragma once

#include <memory>
#include <vector>
#include <iostream>

#include <matrix/matrix.hpp>
#include <matrix/factory/matrix.hpp>

class ParentMatrix {
public:
    struct MatrixDefs {
        int parentMatrixRows;
        int parentMatrixColumns;
        int childMatrixRows;
        int childMatrixColumns;
    };

public:
    ParentMatrix(MatrixDefs defs, MatrixFactory &factory);
    ~ParentMatrix();

public:
    void add(ParentMatrix &matrix);
    void multiply(ParentMatrix &matrix);
    void print();
    bool operator==(const ParentMatrix &matrix) const;

private:
    std::vector<std::vector<Matrix *>> allocate(int rows, int columns);

public:
    std::vector<std::vector<Matrix *>> getStore() const;

private:
    MatrixDefs defs;
    MatrixFactory& factory;
    std::vector<std::vector<Matrix *>> store;
};