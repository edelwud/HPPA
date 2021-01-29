#pragma once

#include <memory>
#include <vector>
#include <iostream>

#include <matrix/matrix.hpp>

template<typename T = Matrix>
class ParentMatrix {
public:
    struct MatrixDefs {
        int parentMatrixRows;
        int parentMatrixColumns;
        int childMatrixRows;
        int childMatrixColumns;
    };

public:
    ParentMatrix(MatrixDefs defs) : defs(defs) { allocate(); };

public:
    std::unique_ptr<ParentMatrix<T>> multiply(ParentMatrix<T>& parentMatrix) {
        if (defs.parentMatrixColumns != parentMatrix.defs.childMatrixRows) {
            throw std::runtime_error("cannot multiply matrix");
        }

        auto result = std::make_unique<ParentMatrix<T>>(MatrixDefs{
                defs.parentMatrixRows,
                parentMatrix.defs.parentMatrixColumns,
                defs.childMatrixRows,
                parentMatrix.defs.childMatrixColumns
        });

#pragma clang loop vectorize(enable) interleave(enable)
        for(int i = 0; i < defs.parentMatrixRows; ++i)
#pragma clang loop vectorize(enable) interleave(enable)
            for(int j = 0; j < parentMatrix.defs.parentMatrixColumns; ++j)
#pragma clang loop vectorize(enable) interleave(enable)
                for(int k = 0; k < defs.parentMatrixColumns; ++k) {
                    result->store[i][j]->add(store[i][k]->multiply(*parentMatrix.getStore()[k][j]));
                }

        return result;
    }

    void print() {
        for (int i = 0; i < defs.parentMatrixRows; i++) {
            for (int j = 0; j < defs.parentMatrixColumns; j++) {
                store[i][j]->print();
                std::cout << std::endl;
            }
        }
    }

private:
    void allocate();

public:
    const std::vector<std::vector<T*>> &getStore() const;

private:
    std::vector<std::vector<T*>> store;
    MatrixDefs defs;
};

template<typename T>
void ParentMatrix<T>::allocate() {
    store.reserve(defs.parentMatrixRows);
#pragma clang loop vectorize(enable) interleave(enable)
    for (int i = 0; i < defs.parentMatrixRows; i++) {
        store.push_back(std::vector<T*>());
#pragma clang loop vectorize(enable) interleave(enable)
        for (int j = 0; j < defs.parentMatrixColumns; j++) {
            store[i].push_back(new T(defs.childMatrixRows, defs.childMatrixColumns));
        }
    }
}

template<typename T>
const std::vector<std::vector<T*>> &ParentMatrix<T>::getStore() const {
    return store;
}
