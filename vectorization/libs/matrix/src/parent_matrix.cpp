#include <parent_matrix.hpp>

ParentMatrix::ParentMatrix(
        ParentMatrix::MatrixDefs defs,
        MatrixFactory& factory)
    :
      defs(defs),
      factory(factory) {
    store = allocate(defs.parentMatrixRows, defs.parentMatrixColumns);
}

void ParentMatrix::multiply(ParentMatrix &matrix) {
    if (defs.parentMatrixColumns != matrix.defs.parentMatrixRows) {
        throw std::runtime_error("cannot multiply matrix");
    }

    auto distStore = matrix.getStore();
    auto resultStore = allocate(defs.parentMatrixRows, matrix.defs.parentMatrixColumns);

    for(int i = 0; i < defs.parentMatrixRows; ++i) {
        for (int k = 0; k < defs.parentMatrixColumns; ++k) {
            for (int j = 0; j < matrix.defs.parentMatrixColumns; ++j) {
                store[i][k]->multiply(distStore[k][j]);
                resultStore[i][j] = store[i][k];
            }
        }
    }

    store = resultStore;
}

bool ParentMatrix::operator==(const ParentMatrix &matrix) const {
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

void ParentMatrix::print() {
    for (int i = 0; i < defs.parentMatrixRows; i++) {
        for (int j = 0; j < defs.parentMatrixColumns; j++) {
            store[i][j]->print();
            std::cout << std::endl;
        }
    }
}

std::vector<std::vector<Matrix *>> ParentMatrix::allocate(int rows, int columns) {
    std::vector<std::vector<Matrix *>> result;
    result.reserve(rows);
    for (int i = 0; i < rows; i++) {
        result.push_back(factory.create(columns, defs.childMatrixRows, defs.childMatrixColumns));
    }
    return result;
}

std::vector<std::vector<Matrix *>> ParentMatrix::getStore() const {
    return store;
}

void ParentMatrix::add(ParentMatrix &matrix) {
    auto [pmr, pmc, cmr, cmc] = matrix.defs;
    for (int i = 0; i < pmr; i++) {
        for (int j = 0; j < pmc; j++) {
            store[i][j]->add(matrix.getStore()[i][j]);
        }
    }
}

ParentMatrix::~ParentMatrix() {
}
