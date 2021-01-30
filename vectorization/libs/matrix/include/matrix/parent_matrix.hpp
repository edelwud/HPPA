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
    ~ParentMatrix() {
        for (auto space : store) {
            for (auto matrix : space) {
                delete matrix;
            }
        }
    }

public:
    std::unique_ptr<ParentMatrix<T>> multiply(ParentMatrix<T>& matrix) {
        if (defs.parentMatrixColumns != matrix.defs.childMatrixRows) {
            throw std::runtime_error("cannot multiply matrix");
        }

        auto result = std::make_unique<ParentMatrix<T>>(MatrixDefs{
                defs.parentMatrixRows,
                matrix.defs.parentMatrixColumns,
                defs.childMatrixRows,
                matrix.defs.childMatrixColumns
        });

        auto distStore = matrix.getStore();
        auto resultStore = result->store;

        for(int i = 0; i < defs.parentMatrixRows; ++i) {
            auto resultStorePart = resultStore[i];
            auto hostStorePart = store[i];
            for (int k = 0; k < defs.parentMatrixColumns; ++k) {
                auto hostValue = hostStorePart[k];
                auto distStorePart = distStore[k];
                for (int j = 0; j < matrix.defs.parentMatrixColumns; ++j) {
                    auto item = *distStorePart[j];
                    hostValue->multiply(item);
                    auto temp = *hostValue;
                    resultStorePart[j]->add(temp);
                }
            }
        }
        return result;
    }

    bool operator==(ParentMatrix<T> const& matrix) const {
        if (defs.parentMatrixRows != matrix.defs.parentMatrixRows ||
            defs.parentMatrixColumns != matrix.defs.parentMatrixColumns ||
            defs.childMatrixRows != matrix.defs.childMatrixRows ||
            defs.childMatrixColumns != matrix.defs.childMatrixColumns) {
            return false;
        }

        for (int i = 0; i < defs.parentMatrixRows; i++) {
            for (int j = 0; j < defs.parentMatrixColumns; j++) {
                if (!(*store[i][j] == *matrix.store[i][j])) {
                    return false;
                }
            }
        }
        return true;
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
    for (int i = 0; i < defs.parentMatrixRows; i++) {
        store.push_back(std::vector<T*>());
        for (int j = 0; j < defs.parentMatrixColumns; j++) {
            store[i].push_back(new T(defs.childMatrixRows, defs.childMatrixColumns));
        }
    }
}

template<typename T>
const std::vector<std::vector<T*>> &ParentMatrix<T>::getStore() const {
    return store;
}
